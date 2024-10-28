import socket
import time

HEADER = 64
FORMAT = "utf-8"
DISCONNECT_MESSAGE = "DISCONNECT"

def get_ip():
    serv = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    serv.connect(("8.8.8.8", 443))
    server_ip = serv.getsockname()[0]
    serv.close()
    return server_ip

PORT = 5050 #socket server port address
SERVER = "192.168.0.3" #socket server ip address
ADDR = (SERVER,PORT)

client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
try:
    client.connect(ADDR)
except Exception as e:
    print("Server is not running: " + e.__str__())
    exit()

def receive_and_print():
    for message in iter(lambda: client.recv(1024).decode(FORMAT), ''):
        print(":", message)
        print("")
        #print(client.recv(2048).decode(FORMAT))
def send(msg):
    message = msg.encode(FORMAT)
    msg_length = len(message)
    send_length = str(msg_length).encode(FORMAT)
    send_length += b' ' * (HEADER - len(send_length))
    client.send(send_length)
    client.send(message)

send("first socket test")
import threading
background_thread = threading.Thread(target=receive_and_print)
background_thread.daemon = True
background_thread.start()
while True:
    msgs = input("Enter message: ")
    send(msgs)
    if msgs == DISCONNECT_MESSAGE:
        break

