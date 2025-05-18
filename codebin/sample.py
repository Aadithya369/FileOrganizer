import csv

# Your list of names
SJTG16 = ["Aadithya A", "Abishek P", "Jess James", "Likitha P", "Shreya Sinha", # ... (all names) ...
          "Muhammed Imaan", "Vaibhavi Kalluri"]

class SJTG16_class:
    def user_input(self, search_name, rate, comments):
        self.search_name = search_name
        self.rate = rate
        self.comments = comments

        # Check if the name exists in the list
        if search_name in SJTG16:
            pass
        else:
            print("The name is not found in SJTG16")

        # Check if the rate is within the range 1-10
        if rate not in range(1, 11):
            print("Only integers from 1-10 are allowed")
        else:
            pass

        # Assign a rating description based on the given rating
        if rate == 10:
            rating_description = "Unrivaled"
        elif rate == 9:
            rating_description = "So close to perfection"
        elif rate == 8:
            rating_description = "Top notch"
        elif rate == 7:
            rating_description = "Impressive"
        elif rate == 6:
            rating_description = "Respectable"
        elif rate == 5:
            rating_description = "Middle of the road"
        elif rate == 4:
            rating_description = "It's alright"
        elif rate == 3:
            rating_description = "Relax, bro"
        elif rate == 2:
            rating_description = "So-so"
        elif rate == 1:
            rating_description = "Not pleased, homie"
        else:
            rating_description = "Invalid rating"

        # Open the file in 'a' (append) mode and write the data
        with open("file.txt", "a") as file:
            file.write(f"Name: {search_name}, Rating: {rate}, Rating Description: {rating_description}, Comments: {comments}\n")

# Take user input
search_name = input("Enter the name: ")
rate = int(input("Enter your rating (1-10): "))
comments = input("Your thoughts: ")

# Create an instance of the SJTG16_class and call user_input method
rating_obj = SJTG16_class()
rating_obj.user_input(search_name, rate, comments)

print("Rating recorded successfully.")
