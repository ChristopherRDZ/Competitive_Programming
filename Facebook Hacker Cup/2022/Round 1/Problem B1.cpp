#include <bits/stdc++.h>
using namespace std;

int cubeta_x[3005];
int cubeta_y[3005];
int arboles_x[3005];
int arboles_y[3005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream entrada;
    entrada.open("watering_well_chapter_1_input.txt");
    ofstream salida;
    salida.open("Solution_B1_22.txt");

    int t, caso = 0;
    long long int MOD = 1000000007;
    entrada >> t;

    while(t--){
        int n, q;

        entrada >> n;
        for(int i = 1; i <= n; i++){
            int a, b;
            entrada >> a >> b;
            arboles_x[a]++;
            arboles_y[b]++;
        }

        entrada >> q;
        for (int i = 1; i <= q; i++){
            int a, b;
            entrada >> a >> b;
            cubeta_x[a]++;
            cubeta_y[b]++;
        }

        long long int res = 0;
        for(int i = 0; i <= 3000; i++){
            int x = i;

            for(int j = 0; j <= 3000; j++){
                if (cubeta_x[j] > 0){
                    long long int aux = x - j;
                    aux = aux * aux;
                    aux = aux * cubeta_x[j];
                    if (aux > MOD) aux -= MOD;
                    aux = aux * arboles_x[i];
                    if (aux > MOD) aux -= MOD;

                    res = res + aux % MOD;
                    if(res > MOD) res -= MOD;
                }
            }
        }

        for (int i = 0; i <= 3000; i++){
            int y = i;
            for(int j = 0; j <= 3000; j++){
                    if(cubeta_y[j] > 0){
                        long long int aux = y - j;
                        aux = aux * aux;
                        aux = aux * cubeta_y[j];
                        if (aux > MOD) aux -= MOD;
                        aux = aux * arboles_y[i];
                        if (aux > MOD) aux -= MOD;

                        res = res + aux % MOD;
                        if(res > MOD) res -= MOD;
                    }
                }
        }

        for(int i = 0; i <= 3000; i++){
            cubeta_x[i] = 0;
            cubeta_y[i] = 0;
            arboles_x[i] = 0;
            arboles_y[i] = 0;
        }

        if(res > MOD) res -= MOD;

        salida << "Case #" << ++caso << ": " << res % MOD << "\n";
    }
    return 0;
}
