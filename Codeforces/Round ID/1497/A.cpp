#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <set>
using namespace std;

int a[102];
int c[102];
map <int, int> cubeta;
map <int, int> res;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    cubeta.clear();
    res.clear();
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
      cin >> a[i];
      cubeta[a[i]]++;
    }
    int aux = 1;
    for (pair<int, int> x: cubeta){
      if (x.second > 1){
        c[aux] = x.first;
        res[x.first] = x.second - 1;
      }else{
        c[aux] = x.first;
      }
      aux++;
    }
    for (pair <int, int> x: res){
      for (int i = 1; i <= x.second; i++){
        c[aux] = x.first;
        aux++;
      }
    }
    for (int i = 1; i <= n; i++){
      cout << c[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}