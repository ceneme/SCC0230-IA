#include "grafo.h"

Grafo:: Grafo(int V, int A){
  numero_cidades = V;
  numero_ruas = A;
  grafo = new vector<int> [numero_cidades];
  visitados = new bool [numero_cidades];
  iniciaVisitados();
}

Grafo:: ~Grafo(){
  delete [] grafo;
  delete [] visitados;
}

void Grafo:: iniciaVisitados(){
  for (int i; i < numero_cidades; i++)
    visitados[i] = false;
}

void Grafo:: dfs(int current){
  visitados[current] = true;
  /*
    Código qualquer
  */
  for(int i = 0; i < (int) grafo[current].size(); i++){
      int next = grafo[current][i];
      if( visitados[next] == false)
	dfs(next);
    }
}

void Grafo:: bfs(int root){
  queue<int> fila;
  fila.push(root);
  visitados[root] = true;
  while (fila.size()){
    int current = fila.front();
    fila.pop();
    // ponho códigos de BFS 
    cout << "Nó atual = " << current << endl;
    for(int i = 0;i < (int) grafo[current].size(); i++){
      int next = grafo[current][i];
      if (visitados[next] == false){
	fila.push(next);
	visitados[next] = true;
      }
    }
  }
}

// int Grafo:: djikstra(int root, int dest){
//   priority_queue<pair<int,int> > fila_prioridade;
//   distancias[root] = 0;
//   fila_prioridade.push(make_pair(0,root));	
//   while(fila_prioridade.size()){
//     // valor da aresta, nó 
//     pair<int,int> current = fila_prioridade.top();	
//     fila_prioridade.pop();
//     int current_no = current.second;
//     cout << "Nó atual = " << current_no << " distancia até ele = " << distancias[current_no] << endl;;
//     for(int i=0;i<(int)grafo[current_no].size();i++){	
//       pair<int,int> next = grafo[current_no][i]; 
//       int soma = distancias[current_no] + next.first;
//       if(distancias[next.second] > soma){
// 	distancias[next.second] = soma;	
// 	fila_prioridade.push(mp(-soma, next.second));
//       }
//     }
//   }
//   return distancias[dest];
// }
