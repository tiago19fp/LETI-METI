import os
from KeyStore import *
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from cryptography.hazmat.backends import default_backend
import base64

salt = os.urandom(16)

kdf = PBKDF2HMAC(
    algorithm=hashes.SHA256(),
    length=32,
    salt=salt,
    iterations=100000,
    backend=default_backend()
)

key = kdf.derive(b"grupo 02 cripto")

ks = KeyStore()
ks.upd("k1",4)
ks.upd("k2",b"xyz")
ks.save("fich.ks", base64.urlsafe_b64encode(key))
ks.load("fich.ks", base64.urlsafe_b64encode(key))
ks.read("k1")

