import socket
client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect(('127.0.0.1',8080))
recevied = client_socket.recv(1024).decode()
socket.sendall(("Hello I am client 3 from 127.0.0.1:8080").encode())
print(recevied)
client_socket.close()
