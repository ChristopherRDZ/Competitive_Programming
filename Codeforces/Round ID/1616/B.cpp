#include <bits/stdc++.h>
using namespace std;

char palabra[1000005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, aux = 0, tot = 0;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> palabra[i];
        }
        bool entro = false;
        for (int i = 1; i <= n; i++){
            if (palabra[i] > palabra[i + 1]){
                cout << palabra[i];
                entro = true;
            }else{
                if (palabra[i] == palabra[i + 1] and entro){
                    cout << palabra[i];
                }else{
                    cout << palabra[i];
                    aux = i;
                    break;
                }
            }
        }
        if (aux == 0){
            for (int i = n; i >= 1; i--) cout << palabra[i];
        }
        for (int i = aux; i >= 1; i--){
            cout << palabra[i];
        }
        cout << "\n";
    }
    return 0;
}