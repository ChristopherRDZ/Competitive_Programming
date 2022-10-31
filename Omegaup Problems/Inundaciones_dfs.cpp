/// Problem Link: https://omegaup.com/arena/problem/Inundaciones
/// DFS/BFS

#include <iostream>
#include <vector>
using namespace std;

int mapa[105][105];
int visited[105][105];

struct dato{
  int pos_i;
  int pos_j;
};

int color;
vector <dato> posis;

void inicio(int i, int j){
  if (visited[i][j] == 0){
    visited[i][j] = 1;
    if (mapa[i][j] == -1) return;
    if (mapa[i][j] == 0) inicio(i - 1, j);
    if (mapa[i][j] == 1) inicio(i, j + 1);
    if (mapa[i][j] == 2) inicio(i + 1, j);
    if (mapa[i][j] == 3) inicio(i, j - 1);
  }
}

void recorre (int i, int j){
  if (visited[i][j] == 0){

    visited[i][j] = color;
    dato aux;
    aux.pos_i = i;
    aux.pos_j = j;
    posis.push_back(aux);

    if (mapa[i][j] == -1) return;
    if (mapa[i][j] == 0) recorre(i - 1, j);
    if (mapa[i][j] == 1) recorre(i, j + 1);
    if (mapa[i][j] == 2) recorre(i + 1, j);
    if (mapa[i][j] == 3) recorre(i, j - 1);
  }else{
    if (visited[i][j] == 1){
      for (dato uwu: posis){
        visited[uwu.pos_i][uwu.pos_j] = 1;
      }
      return;
    }
  }
}

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, m, x, y;
  cin >> n >> m >> x >> y;

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cin >> mapa[i][j];
    }
  }

  inicio(x, y);
  color = 1;

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (visited[i][j] == 0){
        color++;
        recorre(i, j);
        posis.clear();
      }
    }
  }

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (visited[i][j] == 1){
        cout << "1 ";
      }else{
        cout <<"0 ";
      }
    }
    cout << "\n";
  }
  return 0;
}