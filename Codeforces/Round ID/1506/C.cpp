#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    string a, b;
    cin >> a >> b;
    int res = a.size() + b.size();
    int tot;
    int tam;
    for (int i = 0; i < a.size(); i++){
      for (int j = i; j <  a.size(); j++){
        for (int c = 0; c < b.size(); c++){
          tam = j - i + 1;
          if ((c + tam - 1) < b.size()){
            bool p = true;
            for (int d = 0; d < tam; d++){
              if (a[i + d] != b[c + d]){
                p = false;
              }
            }
            if (p){
              tot = a.size() + b.size() - tam * 2;
              res = min(tot, res);
            }
          }
        }
      }
    }
    cout << res;
    cout << "\n";
  }
  return 0;
}