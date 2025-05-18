import socket
HOST = '127.0.0.1'
PORT = 65432
with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as client_socket:
	client_socket.connect((HOST,PORT))
	numbers = input("Enter numbers seperated by commas(eg. 1,2,3):")
	client_socket.sendall(numbers.encode())
	result = client_socket.recv(1024).decode()
	print(f"Sum is recived from server:{result}")
