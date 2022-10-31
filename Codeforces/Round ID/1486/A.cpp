#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

/*bool operator<(const ura&a, const ura&b){
  return a.dano_tot < b.dano_tot;
}*/

long long int bloques[102];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    long long int n, tot = 0, aux = 0, t = 0;
    bool pudo = false;
    cin >> n;
    for (int i = 1; i <= n; i++){
      cin >> bloques[i];
    }
    for (int i = 1; i <= n; i++){
      tot += bloques[i];
      aux += t;
      t++;
      if (tot >= aux){
        pudo = true;
      }else{
        pudo = false;
        break;
      }
    }
    if (pudo){
      cout << "YES";
    }else{
      cout << "NO";
    }
    cout << "\n";
  }
  return 0;
}