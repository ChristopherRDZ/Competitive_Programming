#include <bits/stdc++.h>
using namespace std;

int contar(int n){
  int tot = 0;
  while(n > 0){
    n = n / 10;
    tot++;
  }
  return tot;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int a, b, c, mayor = 0, n1 = 1, n2 = 1, aux = 1;
    cin >> a >> b >> c;
    if (c == a and b == c){
      for (int i = 2; i <= c; i++){
        aux *= 10;
      }
      cout << aux << " " << aux;
    }else{
      for (int i = 2; i <= a; i++) n1 *= 10;
      for (int i = 2; i <= b; i++) n2 *= 10;
      while(true){
        aux = __gcd(n1, n2);
        if (contar(aux) == c){
          break;
        }
        n2++;
      }
      cout << n1 << " " << n2;
    }
    cout << "\n";
  }
  return 0;
}