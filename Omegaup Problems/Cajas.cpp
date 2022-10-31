/// Problem Link: https://omegaup.com/arena/problem/Cajas/
/// Bucket

#include <bits/stdc++.h>
using namespace std;

int cubeta[100005];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int aux, n, mayor = 0, resp = 0, menor = INT_MAX;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> aux;
    cubeta[aux]++;
  }
  for (int i = 1; i <= 100000; i++){
    if (cubeta[i] > 0) resp++;
  }
  cout << resp;
  return 0;
}