import socket

# Define subnets
subnets = {
    16: ("23.36.81.0/28", "23.36.81.1", "23.36.81.14"),
    64: ("23.36.81.16/26", "23.36.81.17", "23.36.81.78"),
    128: ("23.36.81.80/25", "23.36.81.81", "23.36.81.206")
}

def handle_client(client_socket):
    # Receive data from client
    data = client_socket.recv(1024).decode()
    requested_ips = int(data)

    # Check if the requested number of IPs is valid
    if requested_ips in subnets:
        subnet, start_ip, end_ip = subnets[requested_ips]
        response = f"Allocated IPs: {start_ip} to {end_ip} from Subnet {subnet}"
    else:
        response = "Invalid request. Available options: 16, 64, or 128."

    # Send response back to client
    client_socket.send(response.encode())
    client_socket.close()
if __name__ == "__main__":
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("127.0.0.1", 12345))  
    server.listen(1)  
    print("Server listening on port 12345...")

    client_socket, addr = server.accept()
    print(f"Connection from {addr}")
    handle_client(client_socket)

    # Close the server after handling one client
    server.close()

