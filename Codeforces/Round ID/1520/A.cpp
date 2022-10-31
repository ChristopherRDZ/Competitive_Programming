#include <bits/stdc++.h>
using namespace std;

int letras[102];
int cubeta[503];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool f = true;
    for (int i = 0; i < s.size(); i++){
      if (s[i] != s[i + 1]){
        if (cubeta[s[i]] > 0){
          f = false;
          break;
        }
        cubeta[s[i]]++;
      }else{
        if (cubeta[s[i]] > 0){
          f = false;
          break;
        }
      }
    }
    for (int i = 1; i <= 400; i++){
      cubeta[i] = 0;
    }
    if (f) cout << "YES";
    if (!f) cout << "NO";
    cout << "\n";
  }
  return 0;
}