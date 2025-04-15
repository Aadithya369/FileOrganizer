import socket
server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1',8080))
server_socket.listen()
conn,addr = server_socket.accept()
string  = conn.recv(1024).decode()
conn.sendall((string.title()).encode())
conn.close()
server_socket.close()
