import socket
import threading
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

PORT = 5050
#SERVER = socket.gethostbyname(socket.gethostname())
SERVER = get_ip()
ADDR = (SERVER,PORT)

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.bind(ADDR)

userlist = []
def handle_client(conn,addr):
    print(f"New address {addr} connected.")
    connected = True
    while connected:
        msg_length = conn.recv(HEADER).decode(FORMAT)
        if msg_length:
            msg_length = int(msg_length)
            msg = conn.recv(msg_length).decode(FORMAT)
            if msg == DISCONNECT_MESSAGE:
                connected = False
            print(f"sent: {addr} {msg}")
            conn.send("Message received".encode(FORMAT))
            for user in userlist:
                if user[1] != addr:
                    user[0].send(f"{addr} {msg}".encode(FORMAT))

def start():
    server.listen()
    print(f"server is started and listening on {SERVER}:{PORT}")
    while True:
        conn,addr = server.accept()
        thread = threading.Thread(target=handle_client,args=(conn,addr))
        thread.start()
        print(f"Active connections {threading.activeCount() -1}")
        userlist.append((conn,addr))
        print(userlist)
    

print("The server is starting >>>>>>")
start()