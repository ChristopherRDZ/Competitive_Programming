#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

int heroes[102];

/*bool operator<(const ura&a, const ura&b){
  return a.dano_tot < b.dano_tot;
}*/

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
      cin >> heroes[i];
    }
    int tot = 0;
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        if (heroes[i] > heroes[j]){
          tot++;
          break;
        }
      }
    }
    cout << tot;
    cout << "\n";
  }
  return 0;
}