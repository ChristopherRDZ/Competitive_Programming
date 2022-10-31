#include <bits/stdc++.h>
using namespace std;

int digitos[102];

int digs(int n){
  int aux = 0;
  while(n > 0){
    n = n / 10;
    aux++;
  }
  return aux;
}

int llena(int n){
  int aux = 1;
  while(n > 0){
    digitos[aux] = n % 10;
    n = n / 10;
    aux++;
  }
  return aux;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    if (n >= 1 and n < 10){
      cout << 9 - (9 - n);
    }
    int tot = 0;
    int aux;
    if (n >= 10){
      aux = digs(n);
      tot += 9 * (aux - 1);
      aux = llena(n);
      aux--;
      tot += 9 - (9 - (digitos[aux] - 1));
      int ant = digitos[aux];
      bool s = true;
      for (int i = aux - 1; i >= 1; i--){
        if (digitos[i] < ant){
          s = false;
          break;
        }
        if (digitos[i] > ant) break;
        if (digitos[i] == ant) continue;
      }
      for (int i = 0; i <= 100; i++){
        digitos[i] = 0;
      }
      if (s) tot++;
      cout << tot;
    }
    cout << "\n";
  }
  return 0;
}