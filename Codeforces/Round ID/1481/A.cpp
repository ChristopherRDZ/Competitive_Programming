#include <bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int x, y;
    int py = 0, px = 0;
    cin >> x >> y;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
      if (s[i] == 'U'){
        if (y > 0 and py < y){
          py++;
        }
      }
      if (s[i] == 'D'){
        if (y < 0 and py > y){
          py--;
        }
      }
      if (s[i] == 'L'){
        if (x < 0 and px > x){
          px--;
        }
      }
      if (s[i] == 'R'){
        if (x > 0 and px < x){
          px++;
        }
      }
    }
    if (px == x and py == y){
      cout << "YES";
    }else{
      cout << "NO";
    }
    cout << "\n";
  }
  return 0;
}