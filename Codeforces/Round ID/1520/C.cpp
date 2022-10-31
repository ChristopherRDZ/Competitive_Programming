#include <bits/stdc++.h>
using namespace std;

queue <int> impar;
queue <int> par;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    for (int i = 1; i <= n * n; i++){
      if (i % 2 == 0){
        par.push(i);
      }else{
        impar.push(i);
      }
    }
    int aux;
    if (n == 2){
      cout << "-1\n";
    }else{
      for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
          if (!impar.empty()){
            aux = impar.front();
            impar.pop();
            cout << aux << " ";
          }else{
            aux = par.front();
            par.pop();
            cout << aux << " ";
          }
        }
        cout << "\n";
      }
    }
    while(!impar.empty()) impar.pop();
    while(!par.empty()) par.pop();
  }
  return 0;
}