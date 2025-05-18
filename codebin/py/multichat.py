import socket
import threading

clients = []  # Stores connected clients

def broadcast(message, sender_socket):
    """Sends a message to all clients except the sender."""
    for client in clients:
        if client != sender_socket:
            try:
                client.send(message)
            except:
                clients.remove(client)

def handle_client(client_socket):
    """Handles incoming messages from a client."""
    while True:
        try:
            message = client_socket.recv(1024)
            if not message:
                break
            broadcast(message, client_socket)
        except:
            break
    clients.remove(client_socket)
    client_socket.close()

def start_server():
    """Starts the chat server."""
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("0.0.0.0", 5555))  # Listen on all interfaces on port 5555
    server.listen(5)

    print("Server started on port 5555...")

    while True:
        client_socket, _ = server.accept()
        clients.append(client_socket)
        print("New client connected")
        threading.Thread(target=handle_client, args=(client_socket,)).start()

if __name__ == "__main__":
    start_server()

