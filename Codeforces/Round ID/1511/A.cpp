#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, tipo;
    int s1 = 0, s2 = 0, m1 = 0, m2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
      cin >> tipo;
      if (tipo == 1) s1++;
      if (tipo == 2) m1++;
      if (tipo == 3) s2++;
    }
    cout << s1 + s2;
    cout << "\n";
  }
  return 0;
}