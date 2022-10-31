/// Problem Link: https://omegaup.com/arena/problem/Chocolates-CIIC-2015/
/// CIIC-2015 // BINARY SEARCH

#include <iostream>
using namespace std;

int chocolates[100005];

bool intenta(int cant, int n){
  long long int actual = 0;
  for (int i = 1; i <= n; i++){
    actual = actual + chocolates[i] - cant;
    if(actual < 0)return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, maxi = 0;;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> chocolates[i];
    if(chocolates[i] > maxi) maxi = chocolates[i];
  }

  int res, ini = 0, fin = maxi;
  while(ini <= fin){
    int mitad = (ini + fin) / 2;
    bool pudo = intenta(mitad, n);
    if(pudo){
      res = mitad;
      ini = mitad + 1;
    }else{
      fin = mitad - 1;
    }

  }

  cout << res;
  return 0;
}