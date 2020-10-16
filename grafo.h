#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 999999999

class Grafo{
 private:
  int numero_cidades; // N° vértices
  int numero_ruas; // N° arestas
  vector<int> *grafo;
  bool *visitados;
  Grafo();
  ~Grafo();
  void iniciaVisitados();
  void dfs(int current);
  void bfs(int root);
  /* int djikstra(int root, int dest); */
}
