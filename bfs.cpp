#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define numero_cidades 6
#define numero_ruas 6
vector<int> grafo[numero_cidades];
bool visitados[numero_cidades];

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
/*
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
	for(int i=0;i<numero_ruas;i++)
	{
		int a,b;//c;
		// 0 1 
		// 0 2
		cin >> a >> b; // scanf
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	bfs(0);	
}
