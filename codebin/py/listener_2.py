import socket
socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
HOST = '127.0.0.1'
PORT = 8080
socket.connect((HOST,PORT))
socket.sendall(("Hello I am client 2 from 127.0.0.1:8080").encode())
print(socket.recv(1024).decode())
socket.close()
