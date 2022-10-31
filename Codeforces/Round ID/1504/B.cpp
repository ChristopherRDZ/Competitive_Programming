#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;

char a[500002];
char b[500002];
int pre[500002];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int c_a = 0, c_b = 0, u_a = 0, u_b = 0;
    for (int i = 1; i <= n; i++){
      cin >> a[i];
      if (a[i] == '1') u_a++;
      if (a[i] == '0') c_a++;
    }
    for (int i = 1; i <= n; i++){
      cin >> b[i];
      if (b[i] == '1') u_b++;
      if (b[i] == '0') c_b++;
    }
    if (u_a > u_b or u_b > u_a or c_a > c_b or c_b > c_a){
      cout << "NO";
    }else{
      int ceros = 0;
      int unos = 0;
      int aux = 1;
      for (int i = 1; i <= n; i++){
        if (a[i] == '1') unos++;
        if (a[i] == '0') ceros++;
        if (unos == ceros){
          pre[aux] = i;
          aux++;
        }
      }
      bool igual = false;
      bool cambia = false;
      bool pudo = true;
      for (int i = 1; i < aux; i++){
        igual = false;
        cambia = false;
        for (int j = pre[i - 1] + 1; j <= pre[i]; j++){
          if (a[j] != b[j]) cambia = true;
          if (a[j] == b[j]) igual = true;
        }
        if (cambia == true and igual == true){
          pudo = false;
          break;
        }
      }
      for (int i = pre[aux - 1] + 1; i <= n; i++){
        if (a[i] != b[i]){
          pudo = false;
          break;
        }
      }
      if (pudo){
        cout << "YES";
      }else{
        cout << "NO";
      }
    }
    cout << "\n";
  }
  return 0;
}