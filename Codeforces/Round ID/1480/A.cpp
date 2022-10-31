#include <bits/stdc++.h>
#include <queue>
#include <map>

using namespace std;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  string s;
  cin >> t;
  while(t--){
    cin >> s;
    int turno = 1;
    for (int i = 0; i < s.size(); i++){
      if (turno % 2 != 0){
        if (s[i] > 'a'){
          s[i] = 'a';
        }else{
          s[i] = 'b';
        }
      }else{
        if (s[i] < 'z'){
          s[i] = 'z'; 
        }else{
          s[i] = 'y';
        }
      }
      turno++;
      cout << s[i];
    }
    cout << "\n";
  }
  return 0;
}