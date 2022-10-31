/// Problem Link: https://omegaup.com/arena/problem/Orden 
/// Binary Search

#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  long long int n;
  cin >> n;

  long long int ini = 1;
  long long int fin = sqrt(n) * 2;
  long long int mit;

  bool encontro = false;
  while(ini <= fin){
    mit = (ini + fin) / 2;
    long long int aux = (mit * (mit + 1) ) / 2;

    if (n > aux) ini = mit + 1;
    if (n < aux) fin = mit - 1;
    if (n == aux){
      encontro = true;
      break;
    }
    
  }
  /// 1 2 3 4  5  6  7  8  9
  /// 1 3 6 10 15 21 28 36 45
  if (encontro) cout << mit;
  else cout << "NO ES TRIANGULAR";
  
  return 0;
}