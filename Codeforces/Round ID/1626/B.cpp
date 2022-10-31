#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test;
    cin >> test;

    while(test--){
        string s;
        cin >> s;
        int aux = 0, r = 0;
        bool existe = false;
        bool bloqueado = false;
        for (int i = 0; i < s.size() - 1; i++){
            int a = s[i] - 48;
            int b = s[i + 1] - 48;
            int suma = a + b;
            if (suma >=  10){
                existe = true;
                aux = i;
                r = suma;
            }
            if (!existe){
                if (!bloqueado){
                    aux = i;
                    r = suma;
                    bloqueado = true;
                }
            }
        }
        for (int i = 0; i < aux; i++){
            int xd = s[i] - 48;
            cout << xd;
        }
        cout << r;
        for (int i = aux + 2; i < s.size(); i++) {
            int xd = s[i] - 48;
            cout << xd;
        }
        cout << "\n";
    }
    return 0;
}