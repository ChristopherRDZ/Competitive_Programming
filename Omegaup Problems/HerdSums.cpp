/// Problem Link:  https://omegaup.com/arena/problem/herdsums/
/// Sliding Windows

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  int ini=1, fin=1, suma=0, res=0;
  while(ini<=n){
    if(suma<n){
      suma+=fin;
      fin++;
    }
    else if(suma==n){
      res++;
      suma-=ini;
      ini++;
    }
    else if (suma>n){
      suma-=ini;
      ini++;
    }
  }
  cout<<res;
  return 0;
}