import socket
import json
usr_input = input("Enter the word: ")
client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect(('127.0.0.1',8080))
client_socket.sendall((usr_input).encode())
try:
    op = client_socket.recv(1024).decode()
    print(json.loads(op))
except json.JSONDecodeError:
    print(op)
client_socket.close()
