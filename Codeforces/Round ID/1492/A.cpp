#include <bits/stdc++.h>
#include <vector>
         
using namespace std;
             
/*bool operator<(const ura&a, const ura&b){
return a.dano_tot < b.dano_tot;
}*/           


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    long long int n;
    long long int  a, b, c;
    cin >> n >> a >> b >> c;
    long long int x, y, z;
    long long int r1, r2, r3;
    if (n == a or n == b or n == c){
      cout << "0";
    }else{
      if (n < a){
        r1 = a - n;
      }else{
        x = n / a;
        if (x * a < n){ 
          x = x + 1;
        }
        r1 = x * a;
        r1 = r1 - n;
      }
      if (n < b){
        r2 = b - n;
      }else{
        y = n / b;
        if (y * b < n){ 
          y = y + 1;
        }
        r2 = (y * b) - n;
      }
      if (n < c){
        r3 = c - n;
      }else{
        z = n / c;
        if (z * c < n){ 
          z = z + 1;
        }
        r3 = (z * c) - n;
      }
      if (r1 <= r2 and r1 <= r3){
        cout << r1;
      }else{
        if (r2 <= r1 and r2 <= r3){
        cout << r2;
        }else{
          cout << r3;
        }
      }
    }
    cout << "\n";
  }
  return 0;
}