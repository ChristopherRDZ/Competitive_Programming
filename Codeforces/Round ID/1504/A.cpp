#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector <char> fin;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int con = s.size() - 1;
    fin.clear();
    bool pudo = false;
    for (int i = 0; i < s.size(); i++){
      if (!pudo){
        if (s[con] != 'a'){
          fin.push_back('a');
          fin.push_back(s[i]);
          pudo = true;
        }else{
          fin.push_back(s[i]);
        }
      }else{
        fin.push_back(s[i]);
      }
      con--;
    }
    if (pudo){
      cout << "YES\n";
      for (char x: fin){
        cout << x;
      }
    }else{
      cout << "NO";
    }
    cout << "\n";
  }
  return 0;
}