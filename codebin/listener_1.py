import socket                                                               
socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)                   
HOST = '127.0.0.1'                                                          
PORT = 8080                                                                 
socket.connect((HOST,PORT))                                                 
print(socket.recv(1024).decode())                                           
socket.sendall(("Hello I am client 1 from 127.0.0.1:8080").encode())
socket.close()                                                              
