import sys
import os
import base64
import time
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import padding
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives import poly1305

nonce = os.urandom(16)

def chacha_manual_dec(key, token):
    # decode into bytes (from urlsafe base64)
    key_bytes = key
    key_enc = key_bytes[0:32]
    key_poly = key_bytes[32:64]
    token_bytes = base64.urlsafe_b64decode(token)

    version = token_bytes[0]
    timestamp = time.gmtime(int.from_bytes(token_bytes[1:9], byteorder='big'))
    ct = token_bytes[9:len(token_bytes)-16]
    tag = token_bytes[len(token_bytes)-16:len(token_bytes)]

    #print("  m key_enc: " + str(base64.urlsafe_b64encode(key_enc)))
    #print("  m key_poly:  " + str(base64.urlsafe_b64encode(key_poly)))
    #print("  m version:  " + str(version))
    #print("  m ct:       " + str(base64.urlsafe_b64encode(ct)))
    #print("  m tag token:      " + str(base64.urlsafe_b64encode(tag)))
    #print("-----------------------------")

    p = poly1305.Poly1305(key_poly)
    p.update(token_bytes[0:len(token_bytes)-16])
    ctag = p.finalize()
    if(ctag != tag):
        print("hmac tags don't match")
        return

    # decrypt
    algorithm = algorithms.ChaCha20(key_enc, nonce)
    cipher = Cipher(algorithm, mode = None, backend=default_backend())
    decryptor = cipher.decryptor()
    pt = decryptor.update(ct) + decryptor.finalize()
    unpadder = padding.PKCS7(128).unpadder()
    pt = unpadder.update(pt) + unpadder.finalize()
    return pt.decode('utf-8')

def chacha_manual_enc(key, m):
     # decode into bytes (from urlsafe base64)

     key_bytes = key
     key_enc = key_bytes[0:32]
     key_poly = key_bytes[32:64]
     token = bytearray(25 + len(m)) 
     timestamp = int(time.time())
     token[0] = 0b10000000
     token[1:9] = timestamp.to_bytes(8, 'big')
     token_bytes = 25 + 16*len(m)

     padder = padding.PKCS7(128).padder()
     padded_m = padder.update(m.encode('utf-8')) + padder.finalize()

     algorithm = algorithms.ChaCha20(key_enc, nonce)
     cipher = Cipher(algorithm, mode = None, backend=default_backend())
     encriptor = cipher.encryptor()
     ct = encriptor.update(padded_m) + encriptor.finalize()

     token[9:token_bytes-16] = ct

     p = poly1305.Poly1305(key_poly)
     p.update(token[0:token_bytes-16])
     tag = p.finalize()
     #print("-----------------------------")
     #print("  m key_enc: " + str(base64.urlsafe_b64encode(key_enc)))
     #print("  m key_poly:  " + str(base64.urlsafe_b64encode(key_poly)))
     #print("  m version:  " + str(token[0]))
     #print("  m ct:       " + str(base64.urlsafe_b64encode(ct)))
     #print("  m tag token:      " + str(base64.urlsafe_b64encode(tag)))
     #print("-----------------------------")
     
     return base64.urlsafe_b64encode(token+tag)

if __name__ == "__main__":
    
    key = os.urandom(64)
    #print(len(key))

    token = chacha_manual_enc(key, sys.argv[1])
    m1 = chacha_manual_dec(key, token)
    print("key:                " + str(key))
    print("token:              " + str(token))
    print("-----------------------------")
    print("decrypted message:  " + str(m1))
    print("-----------------------------")
