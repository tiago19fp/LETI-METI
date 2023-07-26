from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import hashes, serialization
from KeyStore import *

private_key_server = rsa.generate_private_key(public_exponent=65537,key_size=2048,backend=default_backend())
pem_private_server = private_key_server.private_bytes(encoding=serialization.Encoding.PEM,format=serialization.PrivateFormat.PKCS8,
                                                    encryption_algorithm=serialization.BestAvailableEncryption(b'grupo02server'))
public_key_server = private_key_server.public_key()
pem_public_server = public_key_server.public_bytes(encoding=serialization.Encoding.PEM, format=serialization.PublicFormat.SubjectPublicKeyInfo)

private_key_client = rsa.generate_private_key(public_exponent=65537,key_size=2048,backend=default_backend())
pem_private_client = private_key_client.private_bytes(encoding=serialization.Encoding.PEM,format=serialization.PrivateFormat.PKCS8,
                                                    encryption_algorithm=serialization.BestAvailableEncryption(b'grupo02client'))
public_key_client = private_key_client.public_key()
pem_public_client = public_key_client.public_bytes( encoding=serialization.Encoding.PEM, format=serialization.PublicFormat.SubjectPublicKeyInfo)

def key_gen_server():
    
    ks_server = KeyStore()

    keys_server = pem_public_client + pem_private_server
    ks_server.upd("key",keys_server)
    ks_server.save("fich_server.ks","grupo 02 cripto".encode())
    ks_server.load("fich_server.ks","grupo 02 cripto".encode())

def key_gen_client():

    ks_client = KeyStore()

    keys_client = pem_public_server + pem_private_client
    ks_client.upd("key",keys_client)
    ks_client.save("fich_client.ks","grupo 02 cripto".encode())
    ks_client.load("fich_client.ks","grupo 02 cripto".encode())

# Se for chamada como script...
if __name__ == "__main__":
    key_gen_server()
    key_gen_client()
