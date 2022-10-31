/// Problem Link:  https://omegaup.com/arena/problem/SumasMaximas
/// Sliding Windows

#include <iostream>
using namespace std;

int numeros[1000002];
int sumas[1000002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, subconjunto;
    int n_sumas;
    int maximo = 0;
    cin>>n>>subconjunto;
    for (int i=0;i<n;i++){
        cin>>numeros[i];
    }
    for (int i=0;i<subconjunto;i++){
        sumas [0] = sumas [0] + numeros[i];
    }
    
    n_sumas = n  - subconjunto;

    for (int i = 1 ; i<= n_sumas; i++){
        sumas[i] = sumas[i-1];
        sumas[i] = sumas [i] - numeros[i-1];
        sumas[i] = sumas [i] + numeros[subconjunto];
        subconjunto = subconjunto + 1;
    }

    for (int i=0;i<=n_sumas;i++){
        if (sumas[i]>maximo){
            maximo=sumas[i];
        }
    }

    cout<<maximo;

    return 0;
}