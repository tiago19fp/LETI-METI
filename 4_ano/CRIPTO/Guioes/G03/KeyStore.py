import pickle
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
            data = pickle.dumps(self.d, protocol=pickle.HIGHEST_PROTOCOL)
            print("DEBUG: Dados serializados = ", data)
            print("DEBUG: ... note que permite recuperar dados originais:", pickle.loads(data))
            print("DEBUG: Deveriam agora ser cifrados com chave derivada de:", passphrase)
            fernet = Fernet(passphrase)  
            to_save = data
            encrypted = fernet.encrypt(to_save)   
            handle.write(encrypted)
    def load(self, fich, passphrase):
        # Assegurar que 'passphrase' é fornecida...
        if type(passphrase)!=bytes:
            print("ERRO: Deve fornecer uma 'passphrase' (bytestring) !")
            return
        with open(fich, 'rb') as handle:
            rawdata = handle.read()
            print("DEBUG: Devem ser decifrados (pass=", passphrase, "), antes de recuperar informação...")
            fernet = Fernet(passphrase)
            decrypted = fernet.decrypt(rawdata)
            self.d = pickle.loads(decrypted)
    def upd(self, entry, data, entrypass=None):
        if entrypass==None:
            self.d[entry] = data
        else:
            print("DEBUG: Entrada cifrada...")
    def read(self, entry, entrypass=None):
        if entrypass==None:
            return self.d[entry]
        else:
            print("DEBUG: Entrada cifrada...")

