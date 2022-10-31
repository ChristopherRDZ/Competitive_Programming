#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int a[500002];
map <int, int> sobra;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, ancho;
    cin >> n >> ancho;
    for (int i = 1; i <= n; i++){
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int queda = ancho;
    int res = 1;
    int maxi = 0;
    sobra.clear();
    for (int i = n; i >= 1; i--){
      bool pudo = false;
      if (a[i] <= maxi){
        for (pair<int, int> x: sobra){
          if (a[i] <= x.first and x.second >= 1){
            pudo = true;
            sobra[x.first]--;
            sobra[(x.first - a[i])]++;
            break;
          }
        }
        if (!pudo){
          if (a[i] <= queda){
            queda -= a[i];
          }else{
            res++;
            sobra[queda]++;
            if (queda > maxi){
              maxi = queda;
            }
            queda = ancho - a[i];
          }
        }
      }else{
        if (a[i] <= queda){
          queda -= a[i];
        }else{
          res++;
          sobra[queda]++;
          if (queda > maxi){
            maxi = queda;
          }
          queda = ancho - a[i];
        }
      }
    }
    cout << res;
    cout << "\n";
  }
  return 0;
}