import random
from OpenSSL import crypto

class Certificate:
    def __init__(self):
        self.ca_key = crypto.PKey()
        self.ca_key.generate_key(crypto.TYPE_RSA, 2048)

        self.ca_cert = crypto.X509()
        self.ca_cert.set_version(0)
        self.ca_cert.set_serial_number(1)
        self.ca_cert.get_subject().CN = "EC"
        self.ca_cert.get_subject().ST = "Portugal"
        self.ca_cert.get_subject().L = "Guimaraes"
        self.ca_cert.get_subject().O = "Universidade do Minho"
        self.ca_cert.get_subject().CN = "UMinho"
        self.ca_cert.get_subject().emailAddress = "certificado@uminho.pt"

        self.ca_cert.set_issuer(self.ca_cert.get_subject())
        self.ca_cert.set_pubkey(self.ca_key)
        self.ca_cert.gmtime_adj_notBefore(0)
        self.ca_cert.gmtime_adj_notAfter(24*60*60)
        self.ca_cert.sign(self.ca_key, 'sha256')

    def __create_signed_cert(self, identity):
        k = crypto.PKey()
        k.generate_key(crypto.TYPE_RSA, 2048)

        cert = crypto.X509()
        cert.set_version(0)
        cert.set_serial_number(12)
        cert.get_subject().CN = identity
        cert.set_issuer(self.ca_cert.get_subject())
        cert.set_pubkey(k)
        cert.gmtime_adj_notBefore(0)
        cert.gmtime_adj_notAfter(7*24*60*60)
        
        cert.sign(self.ca_key,'sha256')

        keystore = crypto.PKCS12()
        keystore.set_privatekey(k)
        keystore.set_certificate(cert)
        with open(identity + ".p12", "wb") as f:
            f.write(keystore.export(passphrase="1234".encode(), iter=2048, maciter=1))

    def __saveEC(self):
        with open("EC_self_signed.cer", "wb") as f:
            f.write(crypto.dump_certificate(crypto.FILETYPE_ASN1, self.ca_cert))

    def Start(self):
        self.__create_signed_cert("Server")
        self.__create_signed_cert("Client")
        self.__saveEC()

certificate = Certificate()
certificate.Start()