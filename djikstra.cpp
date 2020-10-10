#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define numero_cidades 6
#define numero_ruas 7
#define INF 999999999
vector<pair<int,int>> grafo[numero_cidades];
bool visitados[numero_cidades];
int distancias[numero_cidades];
int djikstra(int root,int dest)
{
	priority_queue<pair<int,int> > fila_prioridade;
	distancias[root] = 0;
	fila_prioridade.push(make_pair(0,root));	
	while(fila_prioridade.size())
	{
		// valor da aresta, nó 
		pair<int,int> current = fila_prioridade.top();	
		fila_prioridade.pop();
		int current_no = current.second;
		cout << "Nó atual = " << current_no << " distancia até ele = " << distancias[current_no] << endl;;
		for(int i=0;i<(int)grafo[current_no].size();i++)
		{	
			pair<int,int> next = grafo[current_no][i]; 
			int soma = distancias[current_no] + next.first;
			if(distancias[next.second] > soma)
			{
				distancias[next.second] = soma;	
				fila_prioridade.push(mp(-soma,next.second));
			}
		}
	}
	return distancias[dest];
}

/*
   (peso, cidade)

priority_queue: (5,4)(7,2)(9,3)
10 
5
7
15
priority_queue: 5,7,10,15 


void bfs(int root)
{
queue<int> fila;
fila.push(root);
visitados[root] = true;
while(fila.size())
{
int current = fila.front();
fila.pop();
// ponho códigos de BFS 
cout << "Nó atual = " << current << endl;
for(int i=0;i<(int)grafo[current].size();i++)
{
int next = grafo[current][i];
if(visitados[next] == false)
{
fila.push(next);
visitados[next] = true;
}
}
}
}
void dfs(int current)
{
visitados[current] = true;
Código qualquer
for(int i=0;i<(int)grafo[current].size();i++)
{
int next = grafo[current][i];
if(visitados[next] == false)
dfs(next);
}
}
 */

int main()
{	
	for(int i=0;i<numero_cidades;i++)
	{
		// INF 
		distancias[i] = 100000;
	}
	for(int i=0;i<numero_ruas;i++)
	{
		int a,b,distancia;
		// 0 1 
		// 0 2
		cin >> a >> b >> distancia; // scanf
		grafo[a].push_back(make_pair(distancia,b));
		grafo[b].push_back(make_pair(distancia,a));
	}
	cout << "Distancia = " << djikstra(0,4) << endl;
}
