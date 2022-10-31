/// Problem Link: https://omegaup.com/arena/problem/El-juego-de-la-silla/
/// Binary Search

#include <bits/stdc++.h>

using namespace std;

int sillas[100005];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, pregunta;

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> sillas[i];
  sort(sillas + 1, sillas + n + 1);

  cin >> m;
  for (int i = 1; i <= m; i++){
    cin >> pregunta;

    int distancia, mejor = INT_MAX;
    int ini = 1, fin = n, mitad;

    while(ini <= fin){
      mitad = (ini + fin) / 2;

      distancia = abs(pregunta - sillas[mitad]);
      if (distancia < mejor) mejor = distancia;

      if (pregunta > sillas[mitad]) ini = mitad + 1;
      if (pregunta < sillas[mitad]) fin = mitad - 1;
      if (pregunta == sillas[mitad]) break;
    }

    cout << mejor << "\n";
  }
  return 0;
}