/// Problem Link: https://omegaup.com/arena/problem/OMI-CDMX-EDOMEX-2020-Negocios/
/// Binary Search + prefix Sum (One of my favorite problems)

#include <bits/stdc++.h>

using namespace std;

long long int personas[100002];
long long int negocio[100002];
long long int cubeta[100002];
long long int acum[100002];
long long int sumatoria[100002];
long long int ori[100002];

int main()

{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    long long int s = 0;
    long long int ini, fin, mitad;
    long long int pos_i, pos_f;
    long long int aux = 0;
    long long int tot = 0;

    cin >> n;

    for (int i=1;i<=n;i++){
        cin >> personas[i];
        ori[i] = personas[i];

    }

    for (int i=1;i<=n;i++){
        cin >> negocio[i];
        s = s + negocio[i];
        sumatoria[i] = s;
        personas[i+1] += s;

    }

    for (int i = 1; i<=n ; i++){
        ini = i;
        fin = n;
        if (personas[i] <= sumatoria[i]){
            acum[i] += min (ori[i], negocio[i]);
        }else{
            while (ini <= fin){
                mitad = (ini + fin) / 2;
                if (personas[i] < sumatoria[mitad]){
                    fin = mitad - 1;
                }
                if (personas[i] > sumatoria[mitad]){
                    ini = mitad + 1;
                    pos_i = mitad;
                }
                if (personas[i] == sumatoria[mitad]){
                    pos_i = mitad;
                    break;
                }
            }
            cubeta[pos_i+1]--;
            cubeta[i]++;
            if (personas[i] == sumatoria[pos_i]){
                acum[pos_i] += 0;
            }else{
                acum[pos_i+1] += min( (sumatoria[pos_i+1] - sumatoria[pos_i]), (personas[i] - sumatoria[pos_i]));
            }
        }
    }

    for (int i=1;i<=n;i++){
        cubeta[i]+=cubeta[i-1];
        tot = 0;
        if (cubeta[i] > 0){
            tot = cubeta[i] * negocio[i];
        }
        tot = tot + acum[i];
        cout << tot << " ";
    }

    return 0;
} 