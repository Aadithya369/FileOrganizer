import socket
import json
server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1',8080))
server_socket.listen()
conn,addr = server_socket.accept()
usr_input = conn.recv(1024).decode()
vowel = 0
consonant = 0
for c in usr_input:
    if c.lower() in 'aeiou': 
        vowel += 1
    elif c.isalpha():
        consonant += 1
data_to_be_send = json.dumps((vowel,consonant))
conn.sendall(data_to_be_send.encode())
conn.close()
server_socket.close()



