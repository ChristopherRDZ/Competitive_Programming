#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

char p[102];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    bool puede = false;
    for (int i = 1; i <= n; i++){
      cin >> p[i];
    }
    if (k == 0){
      cout << "YES";
    }else{
      int aux = n / 2;
      if (n % 2 != 0){
        aux++;
      }
      if (k >= aux){
        cout << "NO";
      }else{
        int ultimo = n;
        int con = 0;
        puede = true;
        for (int i = 1; i <= n / 2; i++){
          if (p[i] != p[ultimo]){
            puede = false;
            break;
          }else{
            con++;
          }
          ultimo--;
        }
        if (puede){
          cout << "YES";
        }else{
          if (con >= k){
            cout << "YES";
          }else{
            cout << "NO";
          }
          
        }
      }
    }
    cout << "\n";
  }
  return 0;
}