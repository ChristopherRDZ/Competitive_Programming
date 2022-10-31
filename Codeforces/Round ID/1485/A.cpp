#include <bits/stdc++.h>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

unordered_map<int, int> buck;

/*bool operator<(const ura&a, const ura&b){
  return a.dano_tot < b.dano_tot;
}*/


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t, n;
  cin >> t;
  while(t--){
    int a, b;
    cin >> a >> b;
    int x = a;
    int y = b;
    int aux = 0;
    /*
    while (a > 0){
      while(a % b == 0){
        b++;
        aux++;
      }
      if (b < a){
        a = a / b;
      }
      if (b > a){
        a = a / b;
      }
      aux++;
    }
    */
   int op = 0;
   int res = 10000000;
   while(op <= 40){
     a = x;
     b = y + op;
     aux = op;
     while(a > 0){
       if (b == 1 or a == b){
         b++;
       }else{
         a = a / b;
       }
       aux++;
     }
     res = min(res, aux);
     op++;
   }
    cout << res;
    cout << "\n";
  }
  return 0;
}