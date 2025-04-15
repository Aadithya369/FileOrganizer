import subprocess
target = "chat.deepseek.com"
result = subprocess.run(["traceroute",target],capture_output=True,text=True)
print(result.stdout)
