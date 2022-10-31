/// Justt two cases wrong

#include <bits/stdc++.h>
using namespace std;

int a[500005];
int b[500005];

unordered_map <int, int> cuantos_a;
unordered_map <int, int> cuantos_b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ifstream entrada;
    entrada.open("consecutive_cuts_chapter_2_input.txt");
    ofstream salida;
    salida.open("Solution_A_Hard.txt");

    int t, caso = 0;
    entrada >> t;
    while(t--){
        int n, k;
        entrada >> n >> k;

        cuantos_a.clear();
        cuantos_b.clear();

        for (int i = 1; i <= n; i++){
            entrada >> a[i];
            cuantos_a[a[i]]++;

        }
        for (int i = 1; i <= n; i++){
            entrada >> b[i];
            cuantos_b[b[i]]++;
        }

        bool no_muere = true, iguales = false;
        for (auto aux: cuantos_a){
            if (aux.second == n) iguales = true;
            if(cuantos_a[aux.first] != cuantos_b[aux.first]){
                no_muere = false;
                break;
            }
        }

        if(!no_muere){
            salida << "Case #" << ++caso << ": NO\n";
            continue;
        }


        if(iguales){
            salida << "Case #" << ++caso << ": YES\n";
            continue;
        }

        int ini = 1, fin = 1;
        int y = 1;

        while(a[ini] != b[1])
            ini++;

        y = ini;

        bool pudo = false;
        int cuantos = 0, necesita;
        while(ini <= n){
            while(a[y] == b[fin]){
                fin++;
                y++;
                if(fin > n) fin = 1;
                if(y > n) y = 1;
                cuantos++;
                if(cuantos == n){
                    necesita = ini - 1;
                    pudo = true;
                    break;
                }
            }
            if(pudo) break;

            ini++;
            cuantos--;
            fin--;
            while(a[ini] != b[1]) ini++;
            if(ini > y) y = ini;
        }

        if(pudo){
            if((necesita == 0 && k == 1) || (necesita >= 1 && k == 0)){
                salida << "Case #" << ++caso << ": NO\n";
            }else{
                if(n == 2){
                    if((necesita == 0 && k % 2 == 1) || (necesita == 1 && k % 2 == 0)){
                        salida << "Case #" << ++caso << ": NO\n";
                    }else{
                        salida << "Case #" << ++caso << ": YES\n";
                    }
                }else{
                    salida << "Case #" << ++caso << ": YES\n";
                }
            }
        }else{
            salida << "Case #" << ++caso << ": NO\n";
        }

    }
    return 0;
}
