#                                  Relay (R)
# - Sao os componentes que retransmitem as streams multimedia desde os servidores
#   ate aos edge
# - Ao iniciar devem contactar o SC para saber quais os seus vizinhos.
# - Manter uma conexao com os vizinhos e o com o SC atraves de beacons
# - Nao podem comunicar diretamente com os clientes aplicacionais
# - Mantem uma tabela com os pedidos de retransmissao de streams recebidos
# 
#                                 Protocolo de comunicacao
#   R -> SC
#     -TAG, IP, Pedir vizinhos(1)
#     -TAG, IP, beacon(4)??
#   R <- SC
#     -TAG, IP, Receber vizinhos(3), Numero de vizinhos, Tag vizinho, IP vizinho, (...)
#   R -> E
#     -TAG, IP, beacon(4)??

import socket
import _thread
import sys
import time
import random
from time import sleep

SC_IP = "10.0.0.3"
SC_UDP_PORT = 9999

SOURCE_IP = sys.argv[1]
print(SOURCE_IP)

UDP_PORT = 9999

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM) # UDP
sock.bind((SOURCE_IP, UDP_PORT))

times_beacon = {}
neighbours_dict = {}
neighbours_dict["SC"] = SC_IP

edgeWhoRequestedStream = {}
requestID = 0

streamsAvailable = []

def sendBeacon():
    """
    It sends a beacon packet to all the neighbours
    """
    packet = bytearray(1)
    packet[0] = 4
    array = SOURCE_IP.split(".")
    for a in range(len(array)):
        packet.append(int(array[a]))
    while True:
        for b in neighbours_dict:
            sock.sendto(packet, (neighbours_dict[b], SC_UDP_PORT))
        sleep(1)

def sendConnectionRequest():
    """
    It sends a connection request to the server
    """
    packet = bytearray(1)
    packet[0] = 1
    array = SOURCE_IP.split(".")
    for a in range(len(array)):
        packet.append(int(array[a]))
    sock.sendto(packet, (SC_IP, SC_UDP_PORT))

def getNeighbours(packet_received):
    """
    It takes a packet received from the server and prints the tag, tag number and ip of each neighbour
    
    :param packet_received: The packet received from the server
    """
    neighbours_dict.clear()
    neighbours_dict["SC"] = SC_IP
    neighbours = packet_received[2:]
    a = 0
    while(a < len(neighbours)):
        neighbour_tag = chr(neighbours[a])
        neighbour_tag_number = chr(neighbours[a + 1])
        neighbours_ip = socket.inet_ntoa(neighbours[a + 2: a + 6])
        #print("TAG: " + str(neighbour_tag) + str(neighbour_tag_number) + " Ip: " + str(neighbours_ip))
        tag = neighbour_tag + neighbour_tag_number
        neighbours_dict[tag] = neighbours_ip
        a += 6

def askServerForStream(id_stream):
    global requestID
    packet = bytearray(1)
    packet[0] = 12
    array = SOURCE_IP.split(".")
    for a in range(len(array)):
        packet.append(int(array[a]))
    requestID = random.randint(1, 255)
    packet.append(id_stream)
    packet.append(requestID)
    for x in neighbours_dict:
        if x.find("S") != -1:
            sock.sendto(packet, (neighbours_dict[x], UDP_PORT))

def askRelayNeighbourForStream(id_stream):
    packet = bytearray(1)
    packet[0] = 11
    array = SOURCE_IP.split(".")
    for a in range(len(array)):
        packet.append(int(array[a]))
    packet.append(id_stream)
    for x in neighbours_dict:
        if x.find("R") != -1:
            sock.sendto(packet, (neighbours_dict[x], UDP_PORT))

def sendStreamToEdge(packet_received):
    """
    It sends the stream to the edge that requested it
    
    :param packet_received: the packet received from the server
    """
    packet = bytearray(1)
    packet[0] = 14
    array = SOURCE_IP.split(".")
    for a in range(len(array)):
        packet.append(int(array[a]))
    packet.append(packet_received[5])       # stream id
    packet.append(packet_received[7])       # frame number
    packet.append(packet_received[8])       # byte
    for edge in edgeWhoRequestedStream.keys():
        if(packet_received[5] == edgeWhoRequestedStream[edge]):
            #print('ENTREI NO IF ' + str(client))
            sock.sendto(packet, (edge, UDP_PORT))

def sendRequestToEdge(packet_received):
    packet = bytearray(1)
    packet[0] = 16
    array = SOURCE_IP.split(".")
    for a in range(len(array)):
        packet.append(int(array[a]))
    packet.append(packet_received[5])       # stream id
    for edge in edgeWhoRequestedStream.keys():
        if(packet_received[5] == edgeWhoRequestedStream[edge]):
            #print('ENTREI NO IF ' + str(client))
            sock.sendto(packet, (edge, UDP_PORT))

if __name__ == "__main__":

    print("------ R ------")
    sendConnectionRequest()
    readyToSend = 0
    notNeeded = 0
    while True:
        packet_received, addr = sock.recvfrom(1024)  # buffer size is 1024 bytes
        if(packet_received[0] == 3):                            #   RECEIVE LIST OF NEIGHBOURS
            getNeighbours(packet_received)
            #print("NEIGHBOURS: " + str(neighbours_dict))
            _thread.start_new_thread(sendBeacon, ())
        if(packet_received[0] == 4):                            #   RECEIVE BEACON
            a = 1+1
            #print("Beacon received from: " + str(addr))
        if(packet_received[0] == 11):                           #   TRANSMISSION REQUEST FROM EDGE
            edgeWhoRequestedStream[addr[0]] = packet_received[5]
            #print("Pedido de transmissão E -> R")
            if(packet_received[5] not in streamsAvailable):
                serverExists = 0
                for x in neighbours_dict:
                    if x.find("S1") != -1:
                        askServerForStream(packet_received[5])
                        serverExists  = 1
                if(serverExists == 0):
                    askRelayNeighbourForStream(packet_received[5])
        if(packet_received[0] == 13 or packet_received[0] == 14):   #   RECEIVE STREAM FROM SERVER OR NEIGHBOUR RELAY
            if(packet_received[5] not in streamsAvailable):
                streamsAvailable.append(packet_received[5])
                print("Streams Available: "+ str(streamsAvailable))
            #print("Stream recebida R")
            if(readyToSend == 1):
                print('SENT 1')
                sendStreamToEdge(packet_received)
            else:
                if(notNeeded == 0):
                    sendRequestToEdge(packet_received)
            #sendStreamToEdge(packet_received)
        if(packet_received[0] == 17):                               #   CONFIRMATION TO SEND FROM EDGE
            readyToSend = 1
        if(packet_received[0] == 18):                               #   REJECTION TO SEND FROM EDGE
            notNeeded = 1
