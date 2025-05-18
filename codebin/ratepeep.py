import csv
usr_input = input("Enter the Name: ")
names = []
with open("customers-100.csv","r")as file:
    reader = csv.reader(file)
    for row in reader:
        if row:
            names.append(row[0])
if usr_input in names: 
    rating = input(f"Enter your for rating for {usr_input}:")
    print(f"Rating for {usr_input}: {rating}")
else:
    print("Sorry the name is not found :(")
