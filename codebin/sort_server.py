import socket
import json
server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1',8080))
server_socket.listen()
conn,addr = server_socket.accept()
li = conn.recv(1024).decode()
print(json.loads(li).sort())
conn.close()
server_socket.close()
