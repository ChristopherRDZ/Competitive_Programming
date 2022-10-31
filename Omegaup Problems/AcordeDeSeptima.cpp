/// Problem Link: https://omegaup.com/arena/problem/Acorde-de-Septima

#include <bits/stdc++.h>
using namespace std;

int notas[20005];
int acorde[15];
int aux[15];
int indices[20005];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, c;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> notas[i];
  cin >> c;
  for (int i = 1; i <= c; i++) cin >> acorde[i];
  sort(acorde + 1, acorde + c + 1);

  int tam = n - (c - 1);
  int res = 0, aux_2 = 1;

  for (int i = 1; i <= tam; i++){
    int pos_aux = i;

    for (int j = 1; j <= c; j++) aux[j] = notas[pos_aux++];

    sort (aux + 1, aux + c + 1);

    int diferencia;
    int tot = 0;
    for (int j = 1; j <= c; j++){
      int dif = aux[j] - acorde[j];
      if (j == 1) diferencia = dif;
      if (diferencia == dif) tot++;
    }

    if (tot == c){
      res++;
      indices[aux_2++] = i;
    }

  }

  cout << res << "\n";
  for (int i = 1; i < aux_2; i++){
    cout << indices[i] << "\n";
  }

  return 0;
}