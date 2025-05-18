import socket
server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1',8080))
server_socket.listen()
conn,addr = server_socket.accept()
ip = conn.recv(1024).decode()
first_octet = int((ip.split('.')[0]))
if 1 <= first_octet <= 126:
    print("Class A 255.0.0.0")
elif 128 <= first_octet <= 191:
    print("Class B")
elif 192 <= first_octet <= 223:
    print("Class C")
elif 224 <= first_octet <= 239:
    print("Class D")
else:
    print("INVALID IP")
