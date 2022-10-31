/// Problem Link: https://omegaup.com/arena/problem/Direc/
/// Prefix Sum 2D Array

#include <bits/stdc++.h>
using namespace std;

int matriz[1002][1002];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m, p;
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cin >> matriz[i][j];
      matriz[i][j] += matriz[i][j-1] + matriz[i-1][j] - matriz[i-1][j-1];
    }
  }
  cin >> p;
  for (int i = 1; i <= p; i++){
    int a, b, q, r;
    cin >> a >> b >> q >> r;
    int tot = matriz[b][r] - matriz[b][q-1] - matriz[a-1][r] + matriz[a-1][q-1];
    int cas = (b - a + 1) * (r - q + 1);
    int res = tot / cas;
    cout << res << "\n";
  }
  return 0;
    
}