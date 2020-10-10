#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define numero_cidades 5
#define numero_ruas 4
vector<int> grafo[numero_cidades];
bool visitados[numero_cidades];

void dfs(int current)
{
	visitados[current] = true;
	/*
		Código qualquer
	*/
	for(int i=0;i<(int)grafo[current].size();i++)
	{
		int next = grafo[current][i];
		if(visitados[next] == false)
			dfs(next);
	}
}

/*
current = 0
i = 0;
grafo[0][0] -> 1 
0 -> 1,2
1 -> 0
1
2 -> 0
3
4
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
	dfs(0);	
}
