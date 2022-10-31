#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

string horas[1500];
bool palin[1500];

void calc(){
    char hora_0 = '0', hora_1 = '0', mini_0 = '0', mini_1 = '0';
    for (int i = 0; i <= 1439; i++){
        horas[i][0] = hora_0;
        horas[i][1] = hora_1;
        horas[i][2] = mini_0;
        horas[i][3] = mini_1;
        if (hora_0 == mini_1 && hora_1 == mini_0) palin[i] = true;
        mini_1++;
        if (mini_1 > '9'){
            mini_0++;
            mini_1 = '0';
            if (mini_0 > '5'){
                hora_1++;
                mini_0 = '0';
                if (hora_1 > '9'){
                    hora_1 = '0';
                    hora_0++;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int tot = 0;
        string ini;
        int x;
        cin >> ini >> x;
        calc();

        int h = (ini[0] - '0') * 10 + (ini[1] - '0');
        int m = (ini[3] - '0') * 10 + (ini[4] - '0');
        int actual = (h*60) + m;

        if (palin[actual]) tot++;
        int aux = (actual + x) % 1440;

        while(actual != aux){
            if (palin[aux]) tot++;
            aux = (aux + x) % 1440;
        }
        cout << tot;
        cout << "\n";
    }
    return 0;
}