/// Problem Link: https://omegaup.com/arena/problem/Feria-de-San-Marcos
/// Prefix Sum problem

#include <bits/stdc++.h>
using namespace std;

int conciertos[1000005];
int a, b;

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= n; i++){
    cin >> conciertos[i];
  }

  /// Suma de acumulados
  for (int i = 1; i <= n; i++){
    conciertos[i] = conciertos[i] + conciertos[i - 1];
    ///cout << conciertos[i] << " ";
  }
  int res = 0;
  for (int i = 1; i <= p; i++){
    cin >> a >> b;
    res = conciertos[b] - conciertos[a - 1];
    cout << res << "\n";
  }

  return 0;
}