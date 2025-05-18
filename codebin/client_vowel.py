import socket
client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect(('127.0.0.1',8080))
data = "Hello I am Aadithya A from Valathur"
client_socket.sendall((data).encode())
recvied_data = client_socket.recv(1024).decode()
print(f"The vowels and consonants in {data} is {recvied_data}")
client_socket.close()
