/// Problem Link: https://omegaup.com/arena/problem/aldp
/// It can also be solved with binary search

#include <iostream>
using namespace std;

int cubeta[100005];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m, aux;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> aux;
    cubeta[aux] = i;
  }
  cin >> m;
  for (int i = 1; i <= m; i++){
    cin >> aux;
    cout << cubeta[aux] << " ";
  }
  
  return 0;
}