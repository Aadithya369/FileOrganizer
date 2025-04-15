from scapy.all import sniff

def packet_callback(packet):
    # Print a summary of the packet
    print(packet.summary())

# Start sniffing packets
print("Starting network traffic capture...")
sniff(prn=packet_callback, count=10)  # Capture 10 packets
