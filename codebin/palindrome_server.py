import socket
import json
server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1',8080))
server_socket.listen()
conn,addr = server_socket.accept()
string = conn.recv(1024).decode()
rev_string = string[::-1]
if rev_string == string:
    data_to_be_send = json.dumps((string,rev_string))
    conn.sendall((data_to_be_send).encode())
else:
    conn.sendall((f"Well the given string \"{string}\" is not a palindrome").encode())
conn.close()
server_socket.close()

