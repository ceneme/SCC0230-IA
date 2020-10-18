import matplotlib.pyplot as plt
import numpy as np


ncidades = np.linspace(10, 3000, 20, endpoint=True, dtype=int)
averages = np.zeros(20)

for i in range(20):
	avg = 0
	for j in range(4):
		filename = str(j) + "res" + str(i) + ".txt"
		print(filename)

		with open(filename, 'r') as f:
			lines = f.read().splitlines()
			last_line = lines[-1]
			avg += (int(last_line))
	averages[i] = (avg/5)

plt.plot(averages, ncidades, 'o')
plt.show()




