#Cifra de Fernet

import sys
import os
from cryptography.fernet import Fernet
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC

def fernet_enc(ficheiro):
    with open('cifra.key', 'rb') as filekey:
        chave = filekey.read()
        fernet = Fernet(chave)
    with open(ficheiro, 'rb') as file:
        original = file.read()
        encrypted = fernet.encrypt(original)   
    with open('encrypted.enc', 'wb') as encrypted_file:
        encrypted_file.write(encrypted)
    print(encrypted)

def fernet_dec(ficheiro):
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
    if len(sys.argv) != 3:
        print("usage: python cifra.py [setup|enc|dec] [file]")
    else:
        if sys.argv[1] == 'setup':
            # Salts should be randomly generated
            salt = os.urandom(16)
            kdf = PBKDF2HMAC(
                algorithm=hashes.SHA256(),
                length=32,
                salt=salt,
                iterations=100000,
            )
            key = kdf.derive(b"my great password")
        if sys.argv[1] == 'enc':
            fernet_enc(sys.argv[2])
        if sys.argv[1] == 'dec':
            fernet_dec(sys.argv[2])
            
            