/// Problem Link: https://omegaup.com/arena/problem/moscas
/// OMI 2000

#include <iostream>
using namespace std;

int cubeta[60005];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, vive, muere, maximo = 0, fin = 0;
  /// Lectura / cubeta /// aSJKASDJLKW
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>vive>>muere;
    cubeta[vive]++;
    cubeta[muere]--;
    if(muere>fin) fin=muere;
  }
  /// Suma acumulados
  for(int i=1;i<=fin;i++){
    cubeta[i]=cubeta[i]+cubeta[i-1];
  }

  /// Maximo de moscas
  int aux = 0;
  for (int i=0; i<=fin; i++){
    if (cubeta[i]>maximo){
      maximo = cubeta[i];
      aux = i;
    } 
  }

  cout << maximo << "\n";
  
  /// Encontrar todos los rangos
  bool encontro = false;
  for (int i = aux; i <= fin; i++){
    if (maximo == cubeta[i] && encontro == false){
      cout <<  i<< " "; // Empieza
      encontro = true;
    }

    if (cubeta[i]<maximo && encontro == true){
      cout << i << "\n"; // termina 
      encontro = false;
    }
  }
  
  
  return 0;
}