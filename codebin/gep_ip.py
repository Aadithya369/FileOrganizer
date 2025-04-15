import socket
host_name = socket.gethostname()
ip = socket.gethostbyname(host_name)
print(f"{host_name} ip is {ip}")
