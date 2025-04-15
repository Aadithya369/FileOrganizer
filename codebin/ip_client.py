import socket
client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect(('127.0.0.1',8080))
send_mess = ""
while True:
    message = client_socket.recv(1024).decode()
    if(message == "bye"):
        print(message)
        break
    print(message)
    send_mess = input("Enter the input: ")
    client_socket.sendall((send_mess).encode())
client_socket.close()
