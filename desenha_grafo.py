import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
 
f = open('1-2.in', 'r') 
Lines = f.readlines() 

s = Lines[1].split()
alg = int(s[0])
ncidades = int(s[1])
nestradas = int(s[2])

G = nx.Graph()
count = 0
#percorre as linhas do documento gerado por master_random
for line in Lines:
	#quando chega na parte das arestas
	if (count >= ncidades + 2 and (count < ncidades + nestradas + 2)):
		print(line)
		n1 = line.split()[0]
		n2 = line.split()[1]
		if (alg < 2):
			G.add_edge(n1, n2, color='black', weight=1) 
		else:
			w = line.split()[2]
			G.add_edge(n1, n2, color='black', weight=int(w)/400)
	count = count + 1

f = open('1res2.txt', 'r') 
Lines = f.readlines()
caminho = Lines[7]
print(caminho)
caminho = caminho.strip('\n')
caminho = caminho.split(' -> ')

for i in range(len(caminho)-1):
	G.add_edge(caminho[i], caminho[i+1], color="red", weight=5)

print(caminho)

pos = nx.spring_layout(G)
edges = G.edges()
colors = [G[u][v]['color'] for u,v in edges]
weights = [G[u][v]['weight'] for u,v in edges]

nx.draw(G, pos, with_labels=True, node_color='b', node_size = 1700, edges=edges, edge_color=colors, width=weights, edge_cmap=plt.cm.Blues)

plt.show()