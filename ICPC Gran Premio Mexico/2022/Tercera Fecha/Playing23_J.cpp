#include <bits/stdc++.h>
using namespace std;

int disponibles[15];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 13; i++) disponibles[i] = 4;

    int Maria = 0, Juan = 0, rondas;
    int carta1, carta2;

    cin >> rondas;
    cin >> carta1 >> carta2; /// Juan
    Juan = min(carta1, 10) + min(carta2, 10);
    disponibles[carta1]--;
    disponibles[carta2]--;

    cin >> carta1 >> carta2; /// Maria
    Maria = min(carta1, 10) + min(carta2, 10);
    disponibles[carta1]--;
    disponibles[carta2]--;

    for (int i = 1; i <= rondas; i++){
        cin >> carta1;
        int valor = min(10, carta1);
        Maria += valor;
        Juan += valor;
        disponibles[carta1]--;
    }

    bool pudo = false;
    for (int i = 1; i <= 13; i++){
        if(disponibles[i] > 0){
            int valor = min(10, i);

            if(Maria + valor == 23){
                pudo = true;
                cout << valor;
                break;
            }else{
                if(Juan + valor > 23 && Maria + valor <= 23){
                    pudo = true;
                    cout << valor;
                    break;
                }
            }
        }
    }

    if(pudo == false) cout << "-1";
    cout << "\n";

    return 0;
}