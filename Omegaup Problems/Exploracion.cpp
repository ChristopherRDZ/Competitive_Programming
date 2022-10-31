/// Problem Link: https://omegaup.com/arena/problem/Exploracion
/// Sorting problem


#include <bits/stdc++.h>
using namespace std;

int arreglo[50005];
int negativos[50005];

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, n, x, aux = 1;
  cin >> t >> n;

  for (int i = 1; i <= n; i++){
    cin >> x;
    if (x < 0){
      negativos[aux++] = abs(x);
      arreglo[i] = abs(x);
    }else{
      arreglo[i] = x;
    }
  } 

  sort(negativos + 1, negativos + aux);
  sort(arreglo + 1, arreglo + n + 1);

  int res, tot = 0, acum = 0;
  aux = 1;

  for (int i = 1; i <= n; i++){
    if (arreglo[i] == negativos[aux]){
      arreglo[i] *= -1;
      aux++;
    }
    res = arreglo[i] - arreglo[i - 1];
    res = abs(res);
    acum += res;
    if (acum <= t){
      tot++;
    }else{
      break;
    }
  }
  
  cout << tot;
  return 0;
}