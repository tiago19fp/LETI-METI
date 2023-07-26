import pickle
import os, base64
from cryptography.hazmat.primitives.kdf.scrypt import Scrypt
from cryptography.hazmat.backends import default_backend
from cryptography.fernet import Fernet


class KeyStore:
    def __init__(self):
        self.d = {}
    def save(self, fich, passphrase):
        # Assegurar que 'passphrase' é fornecida...
        if type(passphrase)!=bytes:
            print("Deve fornecer uma 'passphrase' (bytestring) !")
            return
        with open(fich, 'wb') as handle:
            data = pickle.dumps(self.d, protocol = pickle.HIGHEST_PROTOCOL)
            #print("DEBUG: Dados serializados = ", data)
            #print("DEBUG: ... note que permite recuperar dados originais:", pickle.loads(data))
            #print("DEBUG: Deveriam agora ser cifrados com chave derivada de:", passphrase)
            #to_save = data # aqui deveria cifrar, etc...
            salt = os.urandom(16)

            kdf = Scrypt(
                salt=salt,
                length=32,
                n =2**14,
                r=8,
                p=1,
                backend=default_backend()
            )

            key = kdf.derive(passphrase)

            fernet = Fernet(base64.urlsafe_b64encode(key))  
            to_save = data
            encrypted = fernet.encrypt(to_save)   
            handle.write(encrypted+salt)

    def load(self, fich, passphrase):
        # Assegurar que 'passphrase' é fornecida...
        if type(passphrase)!=bytes:
            print("ERRO: Deve fornecer uma 'passphrase' (bytestring) !")
            return
        with open(fich, 'rb') as handle:
            rawdata = handle.read()

            salt = rawdata[len(rawdata)-16:]
            kdf = Scrypt(
                salt=salt,
                length = 32,
                n =2**14,
                r=8,
                p=1,
                backend=default_backend()
            )
            key = kdf.derive(passphrase)
            data = rawdata[:len(rawdata)-16]

            fernet = Fernet(base64.urlsafe_b64encode(key))
            decrypted = fernet.decrypt(data)
            self.d = pickle.loads(decrypted)
            
    def upd(self, entry, data, entrypass = None):
        if entrypass==None:
            self.d[entry] = data
        else:
            print("DEBUG: Entrada cifrada...")
    def read(self, entry, entrypass=None):
        if entrypass==None:
            return self.d[entry]
        else:
            print("DEBUG: Entrada cifrada...")
