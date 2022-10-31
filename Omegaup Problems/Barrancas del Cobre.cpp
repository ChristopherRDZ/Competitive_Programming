/// Problem Link: https://omegaup.com/arena/problem/OMI2015LENGUAJE1/
/// Sliding windows
/// OMI 2015

#include <bits/stdc++.h>

using namespace std;
int barrans[50005];

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n, k;
  cin>>n>>k;

  for (int i=1; i<=n; i++){
    cin>>barrans[i];
  }

  int dife, ini = 1, fin = k, suma=0; 
  for (int i=1; i<k; i++){
    dife = barrans[i+1]- barrans[i];
    suma+= dife;
    
  }
  int maxi = suma;
  int restantes = n - k;
  for (int i=1; i<=restantes; i++){
    dife = barrans[ini+1] - barrans[ini];
    suma-=dife;
    dife = barrans[fin+1] - barrans[fin];
    suma+= dife;
    ini++; fin++;
    
    if (suma>maxi) maxi = suma;
    
  }

  cout << maxi;
  
  return 0;
}