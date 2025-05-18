import socket
client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect(('127.0.0.1',8080))
inp = input("Enter the string: ")
client_socket.sendall((inp).encode())
string = client_socket.recv(1204).decode()
print(f"The tile cased is {string}")
client_socket.close()
