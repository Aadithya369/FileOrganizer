import os 
host = input("Enter the Domain name: ")
response = os.system(f"ping -n 1000 {host}")
if response == 0:
    print(f"{host} is reachable")
else:
    print("host is not reachable")