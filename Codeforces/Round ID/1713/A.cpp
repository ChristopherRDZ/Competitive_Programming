#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;

    int x_pos = INT_MIN, x_neg = INT_MAX, y_pos = INT_MIN, y_neg = INT_MAX;
    for(int i = 1; i <= n; i++){
      int x, y;
      cin >> x >> y;
      if(x >=0){
        if(x > x_pos) x_pos = x;
      }
      if(x < 0){
        if(x < x_neg) x_neg = x;
      }
      if(y >=0){
        if(y > y_pos) y_pos = y;
      }
      if(y < 0){
        if(y < y_neg) y_neg = y;
      }
    }
    int res = 0;
    if(x_pos == INT_MIN) x_pos = 0;
    if(y_pos == INT_MIN) y_pos = 0;
    if(x_neg == INT_MAX) x_neg = 0;
    if(y_neg == INT_MAX) y_neg = 0;
    
    res = (x_pos * 2) + (abs(x_neg) * 2) + (y_pos * 2) + (abs(y_neg) * 2);
    cout << res << "\n";
  }
  return 0;
}