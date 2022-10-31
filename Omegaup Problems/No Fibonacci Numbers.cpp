/// Problem Link: https://omegaup.com/arena/problem/nofib

#include <iostream>
using namespace std;

int fibo[32];

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  fibo[1] = 1;
  fibo[2] = 2;

  cin >> n;

  for (int i = 3; i <= 32; i++){
    fibo[i] = fibo [i - 1] + fibo[i - 2];
    if (fibo[i] > n) break;
  }
  int pos_aux = 1;
  for (int i = 1; i < n; i++){
    if (i == fibo[pos_aux]){
      pos_aux++;
      continue;
    }
    cout << i << " ";
  }

  return 0;
}