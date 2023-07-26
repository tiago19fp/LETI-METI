import os
from KeyStore import *
from cryptography.hazmat.primitives.kdf.scrypt import Scrypt
from cryptography.hazmat.backends import default_backend
import base64

salt = os.urandom(16)

kdf = Scrypt(
    salt=salt,
    length=32,
    n=2**14,
    r=8,
    p=1,
    backend=default_backend()
)

key = kdf.derive(b"grupo 02 cripto")

ks = KeyStore()
ks.upd("k1",4)
ks.upd("k2",b"xyz")
ks.save("fich.ks", base64.urlsafe_b64encode(key))
ks.load("fich.ks", base64.urlsafe_b64encode(key))
ks.read("k1")

