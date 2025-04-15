import os
response = os.system("ping -c 1 chat.deepseek.com")
if response == 0:
	print("ping succesfull!")
else:
	print("Ping failed.")
