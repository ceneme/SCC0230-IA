import matplotlib.pyplot as plt
import numpy as np

ncidades = np.linspace(10, 5000, 100, endpoint=True, dtype=int)
averages = np.zeros(100)

for i in range(100):
	avg = 0
	for j in range(5):
		filename = str(i) + "res" + str(j) + ".txt"
		print(filename)

		with open(filename, 'r') as f:
			lines = f.read().splitlines()
			last_line = lines[-1]
			avg += (int(last_line))
	averages[i] = (avg/5)

plt.plot(averages, ncidades, 'o')
plt.show()




