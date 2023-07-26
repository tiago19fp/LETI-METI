
from OpenSSL import crypto
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives import hashes

def load(filename, password):
    file = open(filename,'rb')
    file_bytes = file.read()
    file.close()
    p12store = crypto.load_pkcs12(file_bytes, password)
    certificate = p12store.get_certificate()
    secret_key = p12store.get_privatekey()
    return (certificate, secret_key)

def load_ca_cert(filename):
    file = open(filename,'rb')
    file_bytes = file.read()
    file.close()
    ca_cert = crypto.load_certificate(crypto.FILETYPE_ASN1, file_bytes)
    return ca_cert

def verify_cert(ca_cert, cert):
    store = crypto.X509Store()
    store.add_cert(ca_cert)
    store_ctx = crypto.X509StoreContext(store, cert)
    try:
        store_ctx.verify_certificate()
        return True
    except:
        return False

def print_cert(cert):
    cert_pem = crypto.dump_certificate(crypto.FILETYPE_PEM, cert)
    print(cert_pem)

def example():
    ca_cert = load_ca_cert("CA.cer")
    #print_cert(ca_cert)
    ###
    (s_cert, s_sk) = load("Servidor.p12", b'1234')
    print_cert(s_cert)
    (c_cert, c_sk) = load("Cliente1.p12", b'1234')
    #print_cert(c_cert)
    ###
    r1 = verify_cert(ca_cert, s_cert)
    r2 = verify_cert(ca_cert, c_cert)
    print(r1)
    print(r2)
    ###
    (r_cert, s_sk) = load("random.p12", b'abcdef')
    r3 = verify_cert(ca_cert, r_cert)
    print(r3)

    ###
    certificado =  crypto.dump_certificate(crypto.FILETYPE_PEM, s_cert)
    print(len(certificado))
    server_certificate = crypto.load_certificate(crypto.FILETYPE_PEM, certificado)
    r2 = verify_cert(ca_cert, server_certificate)
    print(r1)

if __name__ == '__main__':
    example()