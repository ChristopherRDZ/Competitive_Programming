#include <bits/stdc++.h>
using namespace std;

int alturas;
vector <int> par;
vector <int> impar;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    par.clear();
    impar.clear();
    for (int i = 1; i <= n; i++){
      cin >> alturas;
      if (alturas % 2 == 0) par.push_back(alturas);
      if (alturas % 2 == 1) impar.push_back(alturas);
    }
    if (par.size() > impar.size()){
      for (int x: par) cout << x << " ";
      for (int x: impar) cout << x << " ";
    }else{
      for (int x: impar) cout << x << " ";
      for (int x: par) cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}