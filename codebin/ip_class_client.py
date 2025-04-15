import socket
client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect(('127.0.0.1',8080))
client_socket.sendall (socket.gethostbyname(socket.gethostname()).encode())
client_socket.close()
