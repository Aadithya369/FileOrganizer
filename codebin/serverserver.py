import socket
HOST = '127.0.0.1'
PORT = 65432
with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as server_socket:
	server_socket.bind((HOST,PORT))
	server_socket.listen()
	print(f"Server is listening on {PORT}:{HOST}...")
	conn,addr = server_socket.accept()
with conn:
	print(f"Connected by {addr}")
	data = conn.recv(1024).decode()
	numbers = list(map(int,data.split(',')))
	print(f"Recived numbers:{numbers}")
	result = sum(numbers)
	conn.sendall(str(result).encode())
	print(f"Sent result:{result}")
