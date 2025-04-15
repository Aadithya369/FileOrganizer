import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

x = np.linspace(0, 5, 20)
y = np.linspace(0, 10, 20)

plt.plot(x, y, 'purple')  # Line
plt.plot(x, y, 'o')       # Dots

a = np.array([2, 1, 5, 7, 4, 6, 8, 14, 10, 9, 18, 20, 22])
plt.plot(a)

plt.show()  # Show the plot
