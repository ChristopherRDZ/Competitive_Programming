/// Problem Link:  https://omegaup.com/arena/problem/Trajineras
/// Binary Search + Sliding Windows

#include <bits/stdc++.h>
using namespace std;

int arreglo[100005];

bool sepuede(int k, int l, int n){
  int suma=0;
  for(int i=1; i<= k; i++){
    suma+=arreglo[i];
    if(suma>l) return false;
  } 

  int inicio=1, fin=k+1;
  
  for(int i=1; i<=n-k; i++) {
    suma=suma+arreglo[fin];
    suma=suma-arreglo[inicio];
      fin++;
      inicio++;
    if (suma > l) return false;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,l;
  cin>>n>>l;
  for(int i=1; i<=n; i++) cin>>arreglo[i];  
  int mayor=0;
  int inicio=1, fin=n;
  while(inicio<=fin){
    int mitad=(inicio+fin)/2;
    if(sepuede(mitad,l,n)==true){
      inicio=mitad+1;
      if (mitad>mayor)mayor=mitad;
    }
    else fin=mitad-1;
  }
  cout<<mayor; 
  return 0;
}