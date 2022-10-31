/// Problem Link: https://omegaup.com/arena/problem/agresivos/
/// Binary Search

#include <bits/stdc++.h>
using namespace std;

int cubiculos[100005];

bool comprueba(int n, int p, int minimo){
  int distancia, sobra = p - 1, ultimo;
  ultimo = cubiculos[1];

  bool puede = true;
  for (int i = 2; i <= n; i++){
    distancia = cubiculos[i] - ultimo;
    if (distancia >= minimo){
      ultimo = cubiculos[i];
      sobra--;
    }
    if (sobra <= 0) break;
  }

  if (sobra > 0) puede = false;

  return puede;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, p;
  int maxi = -INT_MAX;
  cin >> n >> p;

  for (int i = 1; i <= n; i++){
    cin >> cubiculos[i];
    if (cubiculos[i] > maxi) maxi = cubiculos[i];
  }

  sort(cubiculos + 1, cubiculos + n + 1);

  int ini = 1, fin = maxi, mitad;
  int respuesta = 0;
  
  while(ini <= fin){
    mitad = (ini + fin) / 2;

    if (comprueba(n, p, mitad)){
      ini = mitad + 1;
      if (mitad > respuesta) respuesta = mitad;
    }else{
      fin = mitad - 1;
    }
  }

  cout << respuesta;
  return 0;
}