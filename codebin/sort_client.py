import socket
import json
client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect(('127.0.0.1',8080))
my_list = [5,4,3,2,1]
client_socket.sendall((json.dumps(my_list)).encode())
client_socket.close()
