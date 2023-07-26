#Cifra de Fernet

import sys
from cryptography.fernet import Fernet

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
        if sys.argv[1]=='setup':
            key = Fernet.generate_key()
            #fer = Fernet(key)
            ficheiro = open(sys.argv[2],"wb")
            ficheiro.write(key)
            ficheiro.close()
        if sys.argv[1] == 'enc':
            fernet_enc(sys.argv[2])
        if sys.argv[1] == 'dec':
            fernet_dec(sys.argv[2])
            
            