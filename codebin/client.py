import socket

def request_ips(num_ips):
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(("127.0.0.1", 12345))  # Connect to server

    # Send number of IPs requested
    client.send(str(num_ips).encode())

    # Receive and print response from server
    response = client.recv(1024).decode()
    print(response)

    client.close()

if __name__ == "__main__":
    user_input = int(input("Enter number of IPs needed (16, 64, 128): "))
    request_ips(user_input)

