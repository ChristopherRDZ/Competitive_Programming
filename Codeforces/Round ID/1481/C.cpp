#include <bits/stdc++.h>
#include <vector>
using namespace std;

int original[100002];
int deseado[100002];
int pintores[100002];
int res[100002];

vector <int> cubeta[100002];
vector <int> listos[100002];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 100000; i++){
      cubeta[i].clear();
      listos[i].clear();
    }
    for (int i = 1; i <= n; i++){
      cin >> original[i];
    }
    for (int i = 1; i <= n; i++){
      cin >> deseado[i];
      if (deseado[i] != original[i]){
        cubeta[deseado[i]].push_back(i);
      }else{
        listos[deseado[i]].push_back(i);
      }
    }
    for (int i = 1; i <= m; i++){
      cin >> pintores[i];
    }
    int aux;
    for (int i = m; i >= 1; i--){
      aux = cubeta[pintores[i]].size();
      if (aux > 0){
        res[i] = cubeta[pintores[i]][aux - 1];
        listos[pintores[i]].push_back(res[i]);
        cubeta[pintores[i]].pop_back();
      }else{
        if (listos[pintores[i]].size() > 0){
          res[i] = listos[pintores[i]][0];
        }else{
          if (res[i + 1] != 0){
            if (res[i + 1] <= n){
              res[i] = res[i + 1];
            }else{
              res[i] = 1;
            }
          }else{
            res[i] = 1;
          }
        }
      }
    }
    bool puede = true;
    for (int i = 1; i <= m; i++){
      original[res[i]] = pintores[i];
    }
    for (int i = 1; i <= n; i++){
      if (original[i] != deseado[i]){
        puede = false;
        break;
      }
      if (original[i] > n){
        puede = false;
        break;
      }
    }
    if (puede){
      cout << "YES\n";
      for (int i = 1; i <= m; i++){
        cout << res[i] << " ";
      }
      cout << "\n";
    }else{
      cout << "NO\n";
    }
  }
  return 0;
}