#include <bits/stdc++.h>
using namespace std;

map <int, int> pos;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    long long int tot = 0, aux = 0;
    for (int i = 1; i <= n; i++){
      cin >> aux;
      tot += pos[aux - i]++;
    }
    pos.clear();
    cout << tot;
    cout << "\n";
  }
  return 0;
}