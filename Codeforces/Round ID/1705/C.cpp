#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

char letras[200005];

struct ura{
    ll ini;
    ll fin;
    ll pos_ini;
    ll pos_fin;
};

ura preguntas[50];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        ll n, tot = 0, aux, q, c;
        string s;

        cin >> n >> c >> q;
        for (int i = 1; i <= n; i++) cin >> letras[i];

        aux = n;
        for (int i = 1; i <= c; i++){
            ll a, b;
            cin >> a >>  b;
            preguntas[i].ini = a;
            preguntas[i].fin = b;
            preguntas[i].pos_fin = aux + (b - a + 1);
            aux += (b - a + 1);
        }

        preguntas[0].pos_ini = 1;
        preguntas[0].pos_fin = n;
        for (int i = 1; i <= c; i++){
            preguntas[i].pos_ini = preguntas[i - 1].pos_fin + 1;
        }


        for (int i = 1; i <= q; i++){
            ll x;
            cin >> x;

            ll pos_aux, num_letra;
            for (int j = 0; j <= c; j++){
                if (x >= preguntas[j].pos_ini && x <= preguntas[j].pos_fin){
                    pos_aux = j;
                    num_letra = x - preguntas[j].pos_ini + preguntas[j].ini;
                    break;
                }
            }
            while(pos_aux != 0){
                for (int j = 0; j <= c; j++){
                    if (num_letra >= preguntas[j].pos_ini && num_letra <= preguntas[j].pos_fin){
                        pos_aux = j;
                        num_letra = num_letra - preguntas[j].pos_ini + preguntas[j].ini;
                        break;
                    }
                }
            }
            cout << letras[num_letra + 1] << "\n";
        }
    }
    return 0;
}

/*
4 3 3
mark
1 4
5 7
3 8
1
10
12
*/