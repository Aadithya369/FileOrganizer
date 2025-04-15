import socket
import struct

def create_socket():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("127.0.0.1", 65432))
    server_socket.listen(1)
    print("Server listening on port 65432...")
    
    conn, addr = server_socket.accept()
    print(f"Connected by {addr}")
    data = conn.recv(1024)
    print("Received:", data.decode())
    conn.sendall(b"Hello from server!")
    conn.close()
    server_socket.close()

def parse_ipv4_datagram(hex_string):
    raw_data = bytes.fromhex(hex_string)
    fields = struct.unpack("!BBHHHBBH4s4s", raw_data[:20])
    version_ihl = fields[0]
    version = version_ihl >> 4
    ihl = (version_ihl & 0x0F) * 4
    tos = fields[1]
    total_length = fields[2]
    identification = fields[3]
    flags_offset = fields[4]
    ttl = fields[5]
    protocol = fields[6]
    checksum = fields[7]
    src_ip = socket.inet_ntoa(fields[8])
    dest_ip = socket.inet_ntoa(fields[9])
    
    print("IPv4 Datagram Analysis:")
    print(f"Version: {version}")
    print(f"Header Length: {ihl} bytes")
    print(f"Type of Service: {tos}")
    print(f"Total Length: {total_length}")
    print(f"Identification: {identification}")
    print(f"Flags & Fragment Offset: {flags_offset}")
    print(f"Time To Live (TTL): {ttl}")
    print(f"Protocol: {protocol}")
    print(f"Header Checksum: {checksum}")
    print(f"Source IP: {src_ip}")
    print(f"Destination IP: {dest_ip}")

# Hex input (part a)
hex_datagram = "46B8043C1A2B40004006A2F7C0A8016493E0100A"
parse_ipv4_datagram(hex_datagram)

# Run the socket server
def main():
    create_socket()

if __name__ == "__main__":
    main()

