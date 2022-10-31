#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

/*bool operator<(const ura&a, const ura&b){
  return a.dano_tot < b.dano_tot;
}*/

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0){
      if (k > n){
        if (k % n == 0){
          cout << n;
        }else{
          cout << k % n;
        }
      }else{
        cout << k;
      }
    }else{
      int mitad = n / 2 + 1;
      int posis = n - mitad;
      int lleva = (k - 1) / posis;
      if (k > n){
        int original = k % n;
        if (original == 0){
          original = n;
        }
        original = original + lleva;
        original = original % n;
        if (original == 0){
          original = n;
        }
        cout << original;
      }else{
        if (k < mitad){
          cout << k;
        }else{
            int original = k;
            original = original + lleva;
            original = original % n;
            if (original == 0){
              original = n;
            }
          cout << original;
        }
      }
    }
    cout << "\n";
  }
  return 0;
}