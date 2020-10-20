import numpy as np
#import matplotlib.pyplot as plt

files = []

ncidades = np.linspace(10, 5000, 100, endpoint=True, dtype=int)
#ntempos = np.zeros(20)
#plt.plot(ntempos, ncidades, 'o')
#plt.show()

for i in range(5):
	for j in range(100):
		fname = str(i) + "rand" + str(j) + ".in"
		f = open(fname, "w+")
		f.write(str(j) + "\n")
		f.write(str(i) + "\n")
		f.write(str(ncidades[j]) + "\n")
		f.write(str(int(1.5*ncidades[j])) + "\n")
		f.write("5\n")
		f.close()