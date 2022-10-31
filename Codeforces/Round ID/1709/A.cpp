#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int num[200005];
bool puertas[5];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, m, tot = 0;
        cin >> n;

        cin >> num[1] >> num[2] >> num[3];

        puertas[n] = true;
        n = num[n];
        puertas[n] = true;
        n = num[n];
        puertas[n] = true;

        bool pudo = true;
        for (int i = 1; i <= 3; i++){
            if (!puertas[i]){
                pudo = false;
            }
            puertas[i] = false;
        }

        if (pudo) cout << "YES";
        else cout << "NO";

        cout << "\n";
    }
    return 0;
}