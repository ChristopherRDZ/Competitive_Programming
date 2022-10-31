#include <bits/stdc++.h>
using namespace std;

int mon[102];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, k, pos;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
      cin >> mon[i];
    }
    bool posible = false;
    while(k > 0){
      bool crece = true;
      for (int i = 1; i < n; i++){
        if (mon[i] < mon[i + 1]){
          pos = i;
          crece = false;
          break;
        }
      }
      if (crece){
        posible = true;
        break;
      }else{
        mon[pos]++;
        k--;
        if (k <= 0){
          break;
        }
      }
    }
    if (posible){
      cout << "-1\n";
    }else{
      cout << pos << "\n";
    }
  }
  return 0;
}