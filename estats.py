import matplotlib.pyplot as plt
import numpy as np


ncidades = np.linspace(10, 3000, 50, endpoint=True, dtype=int)
averages = np.zeros(50)

for i in range(50):
	avg = 0
	for j in range(4):
		filename = str(i) + "res" + str(j) + ".txt"
		print(filename)

		with open(filename, 'r') as f:
			lines = f.read().splitlines()
			last_line = lines[-1]
			avg += (int(last_line))
	averages[i] = (avg/5)

plt.plot(averages, ncidades, '-o')
plt.show()




