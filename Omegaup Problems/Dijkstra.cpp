/// Problem Link: https://omegaup.com/arena/problem/4Distancia-Dijkstra_TareaArboles
/// Dijkstra Algorithm

#include <bits/stdc++.h>
using namespace std;

struct dato{
  int ind;
  int peso;
};

bool operator <(const dato &a, const dato&b){
  if(a.peso > b.peso) return true;
  else return false;
}

int matriz[1002][1002];
priority_queue <dato> G;
vector <dato> grafo[1002];
long long int pesos[1002];
bool visitados[1002];

void dijkstra(int destino){
  while(!G.empty()){
    dato aux = G.top(); G.pop();
    if(aux.ind == destino) break;
    for(auto x: grafo[aux.ind]){
      int peso_act = pesos[aux.ind] + x.peso;
      if(peso_act < pesos[x.ind]){
        G.push({x.ind, peso_act});
        pesos[x.ind] = peso_act;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, origen, destino;
  cin >> n >> origen >> destino;

  for(int i = 0; i < n; i++){
    pesos[i] = INT_MAX;
    for(int j = 0; j < n; j++){
      cin >> matriz[i][j];
      if(matriz[i][j] > 0){
        grafo[i].push_back({j, matriz[i][j]});
      }
    }
  }

  pesos[origen] = 0;
  G.push({origen, 0});
  dijkstra(destino);
  cout << pesos[destino];
  // TODO: fixme.

  return 0;
}