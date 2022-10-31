#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

char tabl[15][15];

bool prueba(int i, int j){
    bool pudo = true;
    if (tabl[i][j] != '#') return false;

    int suma = 1;
    for (int x = i; x <= 7; x++){
        if (j + suma >= 9) break;   
        if (tabl[x + 1][j + suma] != '#'){
            pudo = false;
            break;
        }
        suma++;
    }
    suma = 1;
    for (int x = i; x >= 2; x--){
        if (j + suma >= 9) break;
        if (tabl[x - 1][j + suma] != '#'){
            pudo = false;
            break;
        }
        suma++;
    }
    suma = 1;
    for (int x = i; x >= 2; x--){
        if (j - suma <= 0) break;
        if (tabl[x - 1][j - suma] != '#'){
            pudo = false;
            break;
        }
        suma++;
    }
    suma = 1;
    for (int x = i; x <= 7; x++){
        if (j - suma <= 0) break;
        if (tabl[x + 1][j - suma] != '#'){
            pudo = false;
            break;
        }
        suma++;
    }
    return pudo;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        for (int i = 1; i <= 8; i++){
            for (int j = 1; j <= 8; j++){
                cin >> tabl[i][j];
            }
        }
        int p = false;
        for (int i = 2; i <= 7; i++){
            for (int j = 2; j <= 7; j++){
                bool res = prueba(i, j);
                if (res){
                    p = true;
                    cout << i << " " << j;
                    break;
                }
            }
            if (p) break;
        }
        cout << "\n";
    }
    return 0;
}