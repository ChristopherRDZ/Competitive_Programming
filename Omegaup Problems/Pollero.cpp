/// Problem Link: https://omegaup.com/arena/problem/POLLEROPEC
/// Greedy problem

#include <bits/stdc++.h>
using namespace std;

int arre[20005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n,t, suma, cont=0;
  cin>>n>>t;

  for(int i=1;i<=n;i++)
    cin>>arre[i];

  sort(arre + 1, arre + n + 1);

  int ini = 1;
  int fin = n;
  int cuantos;
  while(ini < fin){
    suma = arre[ini] + arre[fin];
    if (suma <= t){
      cuantos = fin - ini;
      cont += cuantos;
      ini++;
    }else{
      fin--;
    }
  }

  cout << cont;
  return 0;
}