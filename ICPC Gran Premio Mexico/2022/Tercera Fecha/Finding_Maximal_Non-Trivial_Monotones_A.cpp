#include <bits/stdc++.h>
using namespace std;

char palabra[100005];
struct dato{
    int ini;
    int fin;
};

dato inicios[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> palabra[i];

    bool mono = false;
    bool entre = false;
    int tot = 0;
    int act = 0;
    int pos_aux = 1;
    for (int i = 1; i <= n; i++){
        if (palabra[i] == 'a'){
            if(entre == false){
                inicios[pos_aux].ini = i;
                entre = true;
            }
        }
        if(palabra[i] == 'b'){
            if(entre){
                inicios[pos_aux].fin = i - 1;
                pos_aux++;
            }
            entre = false;
        }
    }

    if(palabra[n] == 'a') inicios[pos_aux++].fin = n;

    for (int i  = 1; i <= pos_aux; i++){
        if(palabra[inicios[i].ini - 1] == 'b' || palabra[inicios[i].fin + 1] == 'b'){
            if(inicios[i].fin - inicios[i].ini + 1 >= 2)
                tot += inicios[i].fin - inicios[i].ini + 1;
        }
    }
    if(inicios[1].ini == 1 && inicios[1].fin == n && n >= 2) tot = n;

    cout << tot;
    cout << "\n";

    return 0;
}