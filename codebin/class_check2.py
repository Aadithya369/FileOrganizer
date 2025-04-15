# Define a simple class
class Dog:
    # Constructor (initialization method)
    def __init__(self, name, breed):
        self.name = name
        self.breed = breed

    # Instance method
    def bark(self):
        return f"{self.name} says Woof!"

# Create instances of the Dog class
dog1 = Dog("Buddy", "Golden Retriever")
dog2 = Dog("Rex", "German Shepherd")

# Access instance attributes
print(f"{dog1.name} is a {dog1.breed}.")
print(f"{dog2.name} is a {dog2.breed}.")

# Call instance method
print(dog1.bark())
print(dog2.bark())
