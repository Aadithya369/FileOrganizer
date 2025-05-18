import socket

# Create a server socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to a local IP and port
server_socket.bind(('127.0.0.1', 8080))

# Start listening for incoming connections, with a maximum queue of 10 clients
server_socket.listen(10)
print("Server is listening for port 8080")

# Accept a client connection
client_socket, client_address = server_socket.accept()
print(f"Connection established with {client_address}")

# Send a message to the client
client_socket.sendall(b"Hello its aadithya from the server")

# Close the client and server sockets
client_socket.close()
server_socket.close()
