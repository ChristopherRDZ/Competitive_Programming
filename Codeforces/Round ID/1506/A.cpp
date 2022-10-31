#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    long long int n, m, x, c, f;
    long long int res;
    cin >> n >> m >> x;
    if (x % n == 0){
      c = x / n;
    }else{
      c = (x / n) + 1;
    }
    f = x % n;
    if (f == 0){
      f = n;
    }
    res = (f - 1)* m + c;
    cout << res;
    cout << "\n";
  }
  return 0;
}