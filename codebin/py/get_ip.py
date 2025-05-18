import socket
import os
def get_ip():
    hostname = socket.gethostname()
    ip = socket.gethostbyname(hostname)
    return ip
ip = get_ip()
print(ip)