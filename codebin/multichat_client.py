import socket
import threading

def receive_messages(client_socket):
    """Continuously listens for incoming messages and prints them."""
    while True:
        try:
            message = client_socket.recv(1024).decode()
            if not message:
                break
            print(message)
        except:
            break

def start_client():
    """Connects to the server and allows sending messages."""
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(("127.0.0.1", 5555))  # Connect to localhost server

    threading.Thread(target=receive_messages, args=(client_socket,), daemon=True).start()

    while True:
        message = input()
        if message.lower() == "exit":
            break
        client_socket.send(message.encode())

    client_socket.close()

if __name__ == "__main__":
    start_client()

