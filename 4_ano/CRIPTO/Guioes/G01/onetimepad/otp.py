#Cifra OTP

import sys
import os
import base64

def otp_enc(msg,ficheiro):
    with open('cifra.key', 'rb') as filekey:
        chave = filekey.read()
        fernet = Fernet(chave)
    with open(ficheiro, 'rb') as file:
        original = file.read()
        encrypted = fernet.encrypt(original)   
    with open('encrypted.enc', 'wb') as encrypted_file:
        encrypted_file.write(encrypted)
    print(encrypted)

def otp_dec(msg,ficheiro):
    with open('cifra.key', 'rb') as filekey:
        chave = filekey.read()
        fernet = Fernet(chave)
    with open(ficheiro, 'rb') as file:
        encryptedFile = file.read()
        decrypted = fernet.decrypt(encryptedFile)
    with open('decrypted.dec', 'wb') as decrypted_file:
        decrypted_file.write(decrypted)
    print(decrypted)
        

# Se for chamada como script...
if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("usage: python cifra.py [setup|enc|dec] [file]")
    else:
        if sys.argv[1]=='setup':
            nBytes = int(sys.argv[2])
            random_bytes = os.urandom(nBytes)
            keyFile = open(sys.argv[3],'wb')
            keyFile.write(base64.b64encode(random_bytes))
            keyFile.close()
        if sys.argv[1] == 'enc':
            otp_enc(mensagem,ficheiro)
        if sys.argv[1] == 'dec':
            otp_dec(sys.argv[2])
