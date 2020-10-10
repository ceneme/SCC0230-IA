#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define numero_cidades 7
#define numero_ruas 7
#define INF 999999999
vector<pair<int,int>> grafo[numero_cidades];
bool visitados[numero_cidades];
int distancias[numero_cidades],distancias_sem_peso[numero_cidades];
int resposta_final[numero_cidades];

void inicializa_variaveis()
{
	for(int i=0;i<numero_cidades;i++)
	{
		resposta_final[i] = INF;
		distancias[i] = INF;
		distancias_sem_peso[i] = INF;
	}
}
void precaulcula_heuristica(int root)
{
	queue<int> fila;
	fila.push(root);
	distancias_sem_peso[root] = 0;
	while(fila.size())
	{
		int current = fila.front();
		fila.pop();
		for(int i=0;i<(int)grafo[current].size();i++)
		{
			int next = grafo[current][i].second;
			if(distancias_sem_peso[next] == INF)
			{
				fila.push(next);
				distancias_sem_peso[next] = distancias_sem_peso[current] + 1;
			}
		}
	}
}

int heuristica(int no)
{
 	return distancias_sem_peso[no];
}

int A_estrela(int root,int dest)
{
	priority_queue<pair<int,int> > fila_prioridade;
	distancias[root] = 0;
	resposta_final[root] = 0;
	fila_prioridade.push(make_pair(0,root));	
	while(fila_prioridade.size())
	{
		// valor da aresta, nó 
		pair<int,int> current = fila_prioridade.top();	
		fila_prioridade.pop();
		int current_no = current.second;
		
		if(current_no == dest) 
			break;

		cout << "No atual = " << current_no << endl;
		for(int i=0;i<(int)grafo[current_no].size();i++)
		{	
			pair<int,int> next = grafo[current_no][i]; 
			int soma = distancias[current_no] + next.first + heuristica(next.second);
			cout << "next = " << next.second << " custo = " << soma << endl;
			if(distancias[next.second] > soma)
			{
				distancias[next.second] = soma;	
				resposta_final[next.second] = resposta_final[current_no] + next.first;
				fila_prioridade.push(mp(-soma,next.second));
			}
		}
	}
	return resposta_final[dest];
}

int main()
{	
	inicializa_variaveis();
	for(int i=0;i<numero_ruas;i++)
	{
		int a,b,distancia;
		// 0 1 
		// 0 2
		cin >> a >> b >> distancia; // scanf
		grafo[a].push_back(make_pair(distancia,b));
		grafo[b].push_back(make_pair(distancia,a));
	}
	precaulcula_heuristica(6);
	cout << "Distancia = " << A_estrela(0,6) << endl;
}
