# Código baseado em https://docs.python.org/3.6/library/asyncio-stream.html#tcp-echo-client-using-streams
import asyncio
from Crypto.Random import new
from cryptography.hazmat.primitives.ciphers.aead import AESGCM
import os
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import dh, padding
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hmac
from OpenSSL import crypto
from example import *

conn_cnt = 0
conn_port = 7654
max_msg_size = 9999

P = 99494096650139337106186933977618513974146274831566768179581759037259788798151499814653951492724365471316253651463342255785311748602922458795201382445323499931625451272600173180136123245441204133515800495917242011863558721723303661523372572477211620144038809673692512025566673746993593384600667047373692203583
G = 44157404837960328768872680677686802650999163226766694797650810379076416463147265401084491113667624054557335394761604876882446924929840681990106974314935015501571333024773172440352475358750668213444607353872754650805031912866692119819377041901642732455911509867728218394542745330014071040326856846990119719675


class ServerWorker(object):
    """ Classe que implementa a funcionalidade do SERVIDOR. """
    def __init__(self, cnt, addr=None):
        """ Construtor da classe. """
        self.id = cnt
        self.addr = addr
        self.msg_cnt = 0

    def process(self, msg):
        """ Processa uma mensagem (`bytestring`) enviada pelo CLIENTE.
            Retorna a mensagem a transmitir como resposta (`None` para
            finalizar ligação) """
        self.msg_cnt += 1

        if(self.msg_cnt == 1):

            public_key_client=int(msg.decode())
            pn = dh.DHParameterNumbers(P, G)
            parameters = pn.parameters(default_backend())

            private_key = parameters.generate_private_key()
            public_key=private_key.public_key()
            public_key_serv=private_key.public_key().public_numbers().y  

            peer_public_numbers=dh.DHPublicNumbers(public_key_client,pn)
            peer_key=peer_public_numbers.public_key(default_backend())
            shared_key=private_key.exchange(peer_key)

            derived_key = HKDF(
                algorithm=hashes.SHA256(),
                length=16,
                salt=None,
                info=b'grupo 02 cripto',
                backend=default_backend()
              ).derive(shared_key)
            
            self.ca_cert = load_ca_cert("CA.cer")
            (s_cert, s_sk) = load("Servidor.p12", b'1234')
            certificado = crypto.dump_certificate(crypto.FILETYPE_PEM, s_cert)
            s_sk_pem = crypto.dump_privatekey(crypto.FILETYPE_PEM,s_sk)
            s_sk_c = serialization.load_pem_private_key(s_sk_pem,password=None,backend=default_backend())

            new_msg=str(public_key_serv).encode()
            signature = s_sk_c.sign(new_msg,padding.PSS(mgf=padding.MGF1(hashes.SHA256()),salt_length=padding.PSS.MAX_LENGTH),hashes.SHA256())
        
            self.key1=derived_key[0:16]
            return signature +certificado+new_msg if len(new_msg) > 0 else None

        if(self.msg_cnt == 2):
            ## VERIFICAR ASSINATURA
            signature = msg[:256]
            certificado_recebido = msg[256:1541]
            msg = msg[1541:]
            #print(signature)

            client_certificate = crypto.load_certificate(crypto.FILETYPE_PEM, certificado_recebido)
            public_rsa=client_certificate.get_pubkey().to_cryptography_key()

            public_rsa.verify(signature,msg,padding.PSS(mgf=padding.MGF1(hashes.SHA256()),salt_length=padding.PSS.MAX_LENGTH),hashes.SHA256())
            client_certificado = crypto.load_certificate(crypto.FILETYPE_PEM, certificado_recebido)
            try:
                verify_cert(self.ca_cert, client_certificado)
                print('certificado verificado com sucesso')
            except:
                print('fail')

            aesgcm = AESGCM(self.key1)
            nonce = msg[0:12]
            msg = msg[12:len(msg)]  
            decryptMessage = aesgcm.decrypt(nonce, msg, None)

            txt = decryptMessage.decode()
            print('%d : %r' % (self.id,txt))
            new_msg = txt.upper().encode()

            aesgcm = AESGCM(self.key1)
            nonce = os.urandom(12)
            encryptMessage = aesgcm.encrypt(nonce, new_msg, None)

            new_msg=nonce+encryptMessage

        else:
            aesgcm = AESGCM(self.key1)
            nonce = msg[0:12]
            msg = msg[12:len(msg)]  
            decryptMessage = aesgcm.decrypt(nonce, msg, None)

            txt = decryptMessage.decode()
            print('%d : %r' % (self.id,txt))
            new_msg = txt.upper().encode()

            aesgcm = AESGCM(self.key1)
            nonce = os.urandom(12)
            encryptMessage = aesgcm.encrypt(nonce, new_msg, None)

            new_msg=nonce+encryptMessage
        
        return new_msg if len(new_msg) > 0 else None


async def handle_echo(reader, writer):
    global conn_cnt
    conn_cnt +=1
    addr = writer.get_extra_info('peername')
    srvwrk = ServerWorker(conn_cnt, addr)
    data = await reader.read(max_msg_size)
    while True:
        if not data: continue
        if(data == b'quit'):
            break
        data = srvwrk.process(data)
        if not data: break
        writer.write(data)
        await writer.drain()
        data = await reader.read(max_msg_size)
    print("[%d]" % srvwrk.id)
    writer.close()


def run_server():
    loop = asyncio.get_event_loop()
    coro = asyncio.start_server(handle_echo, '127.0.0.1', conn_port, loop=loop)
    server = loop.run_until_complete(coro)
    # Serve requests until Ctrl+C is pressed
    print('Serving on {}'.format(server.sockets[0].getsockname()))
    print('  (type ^C to finish)\n')
    try:
        loop.run_forever()
    except KeyboardInterrupt:
        pass
    # Close the server
    server.close()
    loop.run_until_complete(server.wait_closed())
    loop.close()
    print('\nFINISHED!')

run_server()