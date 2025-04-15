import secrets
import string

def generate_random_password(length=12):
    characters = string.ascii_letters + string.digits + string.punctuation

    password = ''.join(secrets.choice(characters) for _ in range(length))
    return password
random_password = generate_random_password(16)
print("Random Password:", random_password)


