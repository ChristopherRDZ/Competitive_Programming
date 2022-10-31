/// Problem Link: https://omegaup.com/arena/problem/Modas/

#include <bits/stdc++.h>
using namespace std;

int vacas[100005];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, l, k;
  cin >> n >> l >> k;

  for (int i = 1; i <= n; i++) cin >> vacas[i];

  sort(vacas + 1, vacas + n + 1); /// O(n log n)

  int res = 0;
  for (int i = 1; i <= n; i++){ // O(n)
    if (vacas[i] <= l){
      res++;
      l += k;
    }else{
      break;
    }
  }

  cout << res;
  return 0;
}