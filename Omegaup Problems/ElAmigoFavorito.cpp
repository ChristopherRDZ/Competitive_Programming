/// Problem Link: https://omegaup.com/arena/problem/El-amigo-favorito
/// Binary Search

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int n, d, k;
    long long int ini, fin, mit, n_izq, n_der, s_1, s_2, necesarios;
    long long int calculo, t_1, t_2, dulces;
    long long int maximo = 0;
    cin >> n >> d >> k;
    ini = 1;
    fin = d;
    n_izq = (k - 1);
    n_der = (n - k);
    while (ini <= fin){
        t_1 = 0;
        t_2 = 0;
        s_1 = 0;
        s_2 = 0;
        mit = (ini + fin) / 2;
        necesarios = mit - 1;
        if (necesarios > n_izq){
            if (n_izq == 0){
                t_1 = mit;
            }else{
                calculo = (((mit-1)*(mit)) / 2) - (((mit - n_izq) * (mit - n_izq - 1)) / 2);
                t_1 = calculo + mit;
                }
        }else{
            if (n_izq <= 0){
                t_1 = mit;
            }else{
                calculo = (necesarios * mit) / 2;
                s_1 = n_izq - necesarios;
                t_1 = calculo + s_1 + mit;
                }
        }
        if (necesarios > n_der){
            if (n_der <= 0){
                t_2 = 0;
            }else{
                calculo = (((mit-1)*(mit)) / 2) - (((mit - n_der) * (mit - n_der - 1)) / 2);
                t_2 = calculo;
                }
        }else{
                calculo = (necesarios * mit) / 2;
                s_2 = n_der - necesarios;
                t_2 = calculo + s_2;
        }
        dulces = t_1 + t_2;
        if (dulces == d){
            maximo = mit;
            break;
        }
        if (dulces > d){
            fin = mit - 1;
        }
        if (dulces < d){
            maximo = mit;
            ini = mit + 1;
        }

    }
    cout << maximo;
    return 0;
}