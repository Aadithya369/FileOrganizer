import socket
def is_valid_ip(ip):
    parts = ip.split(".")
    if(len(parts) == 4):
        for part in parts:
            if not part.isdigit() or not (0 <= int(part) <= 255):
                return False