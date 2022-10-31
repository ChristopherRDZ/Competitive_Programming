#include <bits/stdc++.h>
using namespace std;

int a[102];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  int maximo = 0;
  int ini = 0, fin = 0, aux = 0;
  int x, y;
  for (int i = 1; i <= n; i++){
    if (a[i] == 0){
      aux++;
    }else{
      aux--;
    }
    if (aux > maximo){
      maximo = aux;
      fin = i;
      y = ini + 1;
    }
    if (aux < 0){
      aux = 0;
      ini = i;
    }
  }
  if (maximo > 0){
    for (int i = y; i <= fin; i++){
      if (a[i] == 0){
        a[i] = 1;
      }else{
        a[i] = 0;
      }
    }
    maximo = -1;
    aux = 0;
    for (int i = 1; i <= n; i++){
      if (a[i] == 1){
        aux++;
      }
    }
    cout << aux;
  }else{
    cout << n - 1;
  }
  return 0;
}