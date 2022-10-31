#include <bits/stdc++.h>
using namespace std;

int nums[25];
bool puede[25];

long long int mcm(long long int a, long long int b){
  long long int res = a / __gcd(a, b);
  res = res * b;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++){
    cin >> nums[i];
    puede[i] = true;
  }
  sort(nums + 1, nums + n + 1);
  for (int i = 1; i <= n; i++){
    for (int j = i + 1; j <= n; j++){
      if (nums[j] % nums[i] == 0){
        puede[j] = false;
      }
    }
  }
  int tot = 0;
  for (int i = 1; i <= n; i++){
    if (puede[i]){
      int aux = x / nums[i];
      tot += aux;
    }
  }

  for (int i = 1; i <= n; i++){
    for (int j = i + 1; j <= n; j++){
      if (puede[i] && puede[j]){
        long long int aux = mcm(nums[i], nums[j]); 
        aux = x / aux;
        tot -= aux;
      }
    }
  }

  for (int i = 1; i <= n; i++){
    if (!puede[i]) continue;

    long long int aux = nums[i];
    for (int j = i + 1; j <= n; j++){
      if(!puede[j]) continue;

      for (int k = i; k <= j; k++){
        if (!puede[k]) continue;
        aux = mcm(aux, nums[k]);
      }
      for (int k = j + 1; k <= n; k++){
        if (!nums[k]) continue;

        aux = mcm(aux, nums[k]);
        long long int res = x / aux;
        tot += res;
      }
    }
  }

  cout << tot << "\n";
  return 0;
}