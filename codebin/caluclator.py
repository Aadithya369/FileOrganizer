def add(num1,num2):
     return num1 + num2

def sub(num1,num2):
    return num1 - num2

def mul( num1,num2):
    return num1 * num2

def div(num1,num2):
    return num1 / num2
operation = 0
while(operation < 5):
    operation = int( input("1.Add\n2.Subtraction\n3.Multiplication\n4.Division\n.5.Exit\n"))
    num1 = float(input("Enter Number1: "))
    num2 = float(input("Enter Number2: "))
    if(operation == 5):
        exit(0)
    elif(operation == 1):
        print(add(num1,num2))
    
    elif(operation == 2):
     print(sub(num1,num2))

    elif(operation == 3):
     print(mul(num1,num2))

    elif(operation == 4):
        if(num2 == 0):
            print("Division by zero is not valid")
        else:
            print(div(num1,num2))


    else:
        print("Enter a valid option")
