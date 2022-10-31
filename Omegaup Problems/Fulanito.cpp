/// Problem Link: https://omegaup.com/arena/problem/Fulanito/
/// BinarySearch

#include <iostream>

using namespace std;

long long int acumulado[100005];

int main()

{
  ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    long long int aux;

    cin >> q >> n;

    for (int i = 1; i <= n; i++){
        cin >> acumulado[i];
        acumulado[i] += acumulado[i - 1];
    }

    for (int i = 1; i <= q; i++){
        cin >> aux;

        int ini = 1, fin = n, mitad, indice;
        long long int resto;

        if (aux < acumulado[1]){
          resto = aux;
          indice = 0;
        }else{
          while(ini <= fin){
              mitad = (ini + fin) / 2;

              if (acumulado[mitad] > aux) fin = mitad - 1;
              if (acumulado[mitad] <= aux){
                resto = aux - acumulado[mitad];
                ini = mitad + 1;
                indice = mitad;
              }
          }
        }

        cout << indice << " " << resto << "\n";
    }

    return 0;
}