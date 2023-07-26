import sys
import os
import base64
import time
from cryptography.fernet import Fernet
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes, hmac, padding
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

def fernet_enc(key, m1):
    f = Fernet(key)
    token = f.encrypt(m1.encode('utf-8'))
    return token

def fernet_dec(key, t1):
    f = Fernet(key)
    m1 = f.decrypt(t1)
    return m1.decode('utf-8')

def fernet_manual_dec(key, token):
    # decode into bytes (from urlsafe base64)
    key_bytes = base64.urlsafe_b64decode(key)
    key_hmac = key_bytes[0:16]
    key_enc = key_bytes[16:32]
    token_bytes = base64.urlsafe_b64decode(token)

    version = token_bytes[0]
    timestamp = time.gmtime(int.from_bytes(token_bytes[1:9], byteorder='big'))
    iv = token_bytes[9:25]
    ct = token_bytes[25:len(token_bytes)-32]
    tag = token_bytes[len(token_bytes)-32:len(token_bytes)]

    # print("  m key_hmac: " + str(base64.urlsafe_b64encode(key_hmac)))
    # print("  m key_enc:  " + str(base64.urlsafe_b64encode(key_enc)))
    # print("  m version:  " + str(version))
    # print("  m timestamp:" + time.strftime('%X %x %Z',timestamp))
    # print("  m iv:       " + str(base64.urlsafe_b64encode(iv)))
    # print("  m ct:       " + str(base64.urlsafe_b64encode(ct)))
    # print("  m tag:      " + str(base64.urlsafe_b64encode(tag)))

    # check the mac
    # - tip change key_hmac to key_enc to see the effects
    h = hmac.HMAC(key_hmac, hashes.SHA256(), backend=default_backend())
    h.update(token_bytes[0:len(token_bytes)-32])
    ctag = h.finalize()
    #print("  m tag:      " + str(base64.urlsafe_b64encode(ctag)))
    if(ctag != tag):
        print("hmac tags don't match")
        return    

    # decrypt
    cipher = Cipher(algorithms.AES(key_enc), modes.CBC(iv), backend=default_backend())
    decryptor = cipher.decryptor()
    pt = decryptor.update(ct) + decryptor.finalize()
    unpadder = padding.PKCS7(128).unpadder()
    pt = unpadder.update(pt) + unpadder.finalize()
    # print("  m message:  " + str(pt))
    return pt.decode('utf-8')

def fernet_manual_enc(key, m):
     # decode into bytes (from urlsafe base64)
     key_bytes = base64.urlsafe_b64decode(key)
     key_hmac = key_bytes[0:16]
     key_enc = key_bytes[16:32]
     token = bytearray(57 + len(m)) 
     timestamp = int(time.time())
     token[0] = 0b10000000
     token[1:9] = timestamp.to_bytes(8, 'big')
     token[9:25] = os.urandom(16)
     token_bytes = 57 + 16*len(m)

     padder = padding.PKCS7(128).padder()
     padded_m = padder.update(m.encode('utf-8')) + padder.finalize()
     
     cipher = Cipher(algorithms.AES(key_enc), modes.CBC(token[9:25]), backend=default_backend())
     encriptor = cipher.encryptor()
     ct = encriptor.update(padded_m) + encriptor.finalize()

     token[25:token_bytes-32] = ct

     h = hmac.HMAC(key_hmac, hashes.SHA256(), backend=default_backend())
     h.update(token[0:token_bytes-32])
     tag = h.finalize()
     #print("  m tag2:      " + str(base64.urlsafe_b64encode(tag)))

     return base64.urlsafe_b64encode(token+tag)

if __name__ == "__main__":
    key = Fernet.generate_key()
    token = fernet_enc(key, sys.argv[1])
    m1 = fernet_dec(key, token)
    print("key:                " + str(key))
    print("token:              " + str(token))
    print("decrypted message:  " + m1)
    print("")

    # replace by fernet_manual_enc
    token2 = fernet_manual_enc(key, sys.argv[1])
    m2 = fernet_manual_dec(key, token2)
    print("token 2:            " + str(token2))
    print("decrypted message2: " + m2)
