#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MAXIMO 1000006
#define fator_limitante 3
#define INF 999999999

/*

   Exemplo de entrada:
   Nome de cada uma das cidades

   Sao_Paulo
   Londres
   Sao_carlos
   Campinas
   Paris
   Paris Sao_Carlos 1
   Sao_Carlos Londres 7
   Campinas Sao_Paulo 3
   .
   .
   .
   .


 */
vector<int> caminho;
int pai_arvore[MAXIMO];
int numero_cidades,numero_ruas;
string cidades_id[MAXIMO];
map<string,int> id_cidades;
vector<pair<int,int> > grafo[MAXIMO];
bool visitados[MAXIMO];
int distancias[MAXIMO],distancias_sem_peso[MAXIMO];
int resposta_final[MAXIMO];
void inicializa_variaveis(int root)
{
	pai_arvore[root] = -1;
	caminho.clear();
	for(int i=0;i<numero_cidades;i++)
	{
		resposta_final[i] = INF;
		distancias[i] = INF;
		distancias_sem_peso[i] = INF;
	}
}
void precalcula_heuristica(int root)
{
	/*
		Cálculo da heurística que será utilizada
		Adotado como padrão heurística de distâncias sem peso
		Objetivo: Tentativa de não se distanciar muito do nó de resposta ainda que os custos indiquem um ramo nesse sentido
	*/
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
	return distancias_sem_peso[no]*10; // valor atribuido para heurística
}

int A_estrela(int root,int dest, bool flag_idaestrela)
{
	precalcula_heuristica(dest);
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

		for(int i=0;i<(int)grafo[current_no].size();i++)
		{	
			pair<int,int> next = grafo[current_no][i]; 
			/*
				soma importante, principal diferença em relação ao djikstra acréscimo da heurística no peso de comparação da priority queue
			*/
			int soma = distancias[current_no] + next.first + heuristica(next.second);
			if(distancias[next.second] > soma)
			{
				distancias[next.second] = soma;	
				resposta_final[next.second] = resposta_final[current_no] + next.first;
				pai_arvore[next.second] = current_no;
				/* 
					A diferença entre A estrela e IDA estrela é o uso do fator limitante na heurística
					para não reescrever o código, adicionei uma flag para saber qual estou usando no momento
				*/
				if (flag_idaestrela == false or (flag_idaestrela == true and  heuristica(next.second) <= fator_limitante))
					fila_prioridade.push(mp(-soma,next.second));
			}
		}
	}
	return resposta_final[dest];
}
int djikstra(int root,int dest)
{
	priority_queue<pair<int,int> > fila_prioridade;
	distancias[root] = 0;
	fila_prioridade.push(make_pair(0,root));	
	while(fila_prioridade.size())
	{
		pair<int,int> current = fila_prioridade.top();	
		fila_prioridade.pop();
		int current_no = current.second;
		for(int i=0;i<(int)grafo[current_no].size();i++)
		{	
			pair<int,int> next = grafo[current_no][i]; 
			int soma = distancias[current_no] + next.first;
			if(distancias[next.second] > soma)
			{
				distancias[next.second] = soma;	
				fila_prioridade.push(mp(-soma,next.second));
				pai_arvore[next.second] = current_no;
			}
		}
	}
	return distancias[dest];
}
int bfs(int root,int dest)
{
	queue<int> fila;
	fila.push(root);
	visitados[root] = true;
	distancias[root] = 0;
	while(fila.size()) 
	{
		int current = fila.front();
		fila.pop();
		for(int i=0;i<(int)grafo[current].size();i++)
		{
			int next = grafo[current][i].second;
			if(visitados[next] == false)
			{
				pai_arvore[next] = current;
				fila.push(next);
				visitados[next] = true;
				distancias[next] = distancias[current] + 1;
			}
		}
	}
	return distancias[dest];
}
void dfs(int current,int dest)
{
	visitados[current] = true;
	if(visitados[dest] == true) // se já chegamos no destino podemos encerrar o código
		return ;
	for(int i=0;i<(int)grafo[current].size();i++)
	{
		int next = grafo[current][i].second;
		if(visitados[next] == false)
		{
			pai_arvore[next] = current;
			dfs(next,dest);
		}
	}
}
void printa_caminho(int root,int dest)
{
	int curr = dest;
	int cont = 0;
	while(curr!=-1)
	{
		caminho.pb(curr);
		curr = pai_arvore[curr];
		cont++;
	}
	
	reverse(caminho.begin(),caminho.end());
	cout << "Caminho de cidades é: \n";
	for(int i=0;i<caminho.size();i++)
	{
		cout << cidades_id[caminho[i]]; 
		if(i!=caminho.size()-1)
			cout << " -> ";
		else
			cout << endl;
	}
	
}
int main()
{	
	string nome_saida;
	cin >> nome_saida;
    const char *c = nome_saida.c_str(); //converte string para char*
    freopen (c, "w+", stdout); //inicializa arquivo para guardar o resultado

	cout << "Qual operação vai ser realizada?" << endl; // determina se vai rodar BFS,DFS,Djikstra,Aestrela,IDAestrela respectivamente
	int id_operacao = 0;
	cin >> id_operacao;

	cout << "insira quantidade de cidades e quantidade de arestas (ruas) " << endl;
	cin >> numero_cidades >> numero_ruas;
	for(int i=0;i<numero_cidades;i++)
	{
		string nome_atual;
		cin >> nome_atual;
		cidades_id[i] = nome_atual; // nome da cidade atribuida a um ID
		id_cidades[nome_atual] = i; // ID atribuido ao nome de uma cidade
	}
	cout << "insira as arestas" << endl;
	if(id_operacao < 2) // grafo sem peso
	{
		for(int i=0;i<numero_ruas;i++)
		{
			int a,b;
			string aa,bb;
			cin >> aa >> bb;
			a = id_cidades[aa];
			b = id_cidades[bb];
			grafo[a].push_back(make_pair(0,b));
			grafo[b].push_back(make_pair(0,a));
		}
	}
	else
	{
		for(int i=0;i<numero_ruas;i++)
		{
			int a,b,distancia;
			string aa,bb;
			cin >> aa >> bb >> distancia;
			a = id_cidades[aa];
			b = id_cidades[bb];
			grafo[a].push_back(make_pair(distancia,b));
			grafo[b].push_back(make_pair(distancia,a));
		}
	}
	cout << "Qual o nome da cidade de origem e de destino?" << endl;
	string inicio,destino;
	cin >> inicio >> destino;
	// transformo em nós
	int id_inicio,id_destino;
	id_inicio = id_cidades[inicio];
	id_destino = id_cidades[destino];
	inicializa_variaveis(id_inicio);
	
	cout << "Início da execução" << endl;
	//contamos o tempo de execução a partir de agora
	auto t1 = std::chrono::high_resolution_clock::now();
    
	if(id_operacao == 0)
		bfs(id_inicio,id_destino);
	else if(id_operacao == 1)
		dfs(id_inicio,id_destino);
	else if(id_operacao == 2)
		djikstra(id_inicio,id_destino);
	else if(id_operacao == 3)
		A_estrela(id_inicio,id_destino,false);
	else
		A_estrela(id_inicio,id_destino,true);

	//terminamos de contar o tempo e calculamos a duração
	auto t2 = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    cout << "Fim da execução" << endl;

	printa_caminho(id_inicio,id_destino);

	//imprime o tempo de execução ao final
	cout << duracao << endl;

}
