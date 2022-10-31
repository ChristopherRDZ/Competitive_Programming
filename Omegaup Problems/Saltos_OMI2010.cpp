/// Problem Link: https://omegaup.com/arena/problem/L--OMI2010-Saltos
// OMI 2010 - GCD and LCM

#include <iostream>
#include <algorithm>
using namespace std;

long long int mcm(long long int a, long long int b){
  return (a * b) / __gcd(a, b);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int m, n, a, d, f, c;
  long long int pasos_arriba, pasos_derecha;
  cin >> m >> n; //filas y columnas
  cin >> a >> d; // Pasos hacia arriba y derecha
  cin >> f >> c; // Fila y columna donde se empieza

  pasos_arriba = mcm(a, m) / a;
  pasos_derecha = mcm(d, n) / d;

  cout << mcm(pasos_arriba, pasos_derecha);

  return 0;
}