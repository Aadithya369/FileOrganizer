import numpy as np
with open("inverse.txt", "r") as file:  
    a= file.readlines()
matrix = np.array([list(map(int, line.split()))for line in a])
inverse_matrix=np.linalg.inv(matrix)
print(inverse_matrix)
y=str(inverse_matrix)
with open("inverse.txt", "w") as file:
    x=file.write(y) 
