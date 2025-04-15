import random
random_num = random.randint(1,1000)
guess = 0
count = 0 
while guess != random_num:
    guess = int(input("Enter your guess ;)"))
    count = count + 1
    if(guess > random_num):
         print("Go lower!")
    elif(guess < random_num):
        print("Go higher!")
    else:
        print("You guess it after",count,"attempts");
        print("Hooray! you guessed it right!")
