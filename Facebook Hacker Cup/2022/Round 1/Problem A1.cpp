#include <bits/stdc++.h>
using namespace std;

int a[500002];
int b[500002];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream entrada;
    entrada.open("consecutive_cuts_chapter_1_input.txt");
    ofstream salida;
    salida.open("Solution_A.txt");

    int t;
    entrada >> t;

    int caso = 0;
    while(t--){
        int n, k;
        entrada >> n >> k;
        for(int i = 1; i <= n; i++) entrada >> a[i];
        for (int i = 1; i <= n; i++) entrada >> b[i];

        int ini = 1;
        while(a[ini] != b[1])
            ini++;

        int necesita = ini - 1;
        bool puede = true;
        for(int i = 1; i <= n; i++){
            if(a[ini] != b[i]){
                puede = false;
                break;
            }
            ini++;
            if(ini > n) ini = 1;
        }

        if(!puede){
            salida << "Case #" << ++caso << ": NO\n";
        }else{
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
        }

    }
    return 0;
}
