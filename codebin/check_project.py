import random

# Randomly generate a number between 0 and 9
a = random.randint(0, 9)
count = 0

while True:
    # Prompt the user to enter a number
    input_1 = int(input("Enter the number: "))
    count += 1
    if input_1 < a:
        print("Higher number please")
    elif input_1 > a:
        print("Lower number please")
    else:
        print(f"You guessed the right number with {count} guesses")
        break
