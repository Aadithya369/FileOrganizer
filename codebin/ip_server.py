import socket
server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1',8080))
server_socket.listen()
conn,addr = server_socket.accept()
while True:
    message = input("Enter the message: ")
    conn.sendall(message.encode())
    signal = conn.recv(1024).decode()
    if signal == "bye" or message == "bye":
        print(signal)
        conn.sendall(("bye").encode())
        break
    print(signal)
server_socket.close()
conn.close()

