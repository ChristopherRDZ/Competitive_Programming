/// Problem Link: https://omegaup.com/arena/problem/ritualcirc
/// Sliding Windows

#include <bits/stdc++.h>

using namespace std;

int alturas[100002];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long int n, p_i = 0, p_d = 0, mayor = 0, aux = 0, i_i, i_d;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> alturas[i];
    }
        sort (alturas + 1, alturas + n + 1);
    aux = abs (alturas[1] - alturas[2]);
    if (aux > mayor){
        mayor = aux;
    }
    aux = abs (alturas[n] - alturas[n-1]);
    if (aux > mayor){
        mayor = aux;
    }
    p_d = 3;
    p_i = 4;
    i_d = 1;
    i_i = 2;
    /// con esto simulamos una grafica (arreglo) donde en el centro estan los valores
    /// más altos, y en ambos extremos, sus valores iran disminuyendo
    while (1 == 1){
        aux = abs (alturas[p_d] - alturas[i_d]);
        if (aux > mayor){
            mayor = aux;
        }
        p_d = p_d + 2;
        i_d = i_d + 2;
        if (p_d > n){
            break;
        }
    }
    while (1 == 1){
        aux = abs (alturas[p_i] - alturas[i_i]);
        if (aux > mayor){
            mayor = aux;
        }
        p_i = p_i + 2;
        i_i = i_i + 2;
        if (p_i > n){
            break;
        }
    }
    cout << mayor;
    return 0;
}


