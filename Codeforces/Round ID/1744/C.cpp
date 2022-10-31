#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

char colores[200005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        char aux;
        cin >> n >> aux;
        for (int i = 1; i <= n; i++) cin >> colores[i];

        int tot = 0, ult = 0;
        bool encontro = false;
        int res = 0;
        for (int i = 1; i <= n; i++){
            if(aux == colores[i] && encontro == false){
                encontro = true;
                tot = -1;
                ult = i;
            }
            if(encontro){
                tot++;
            }
            if(colores[i] == 'g' && encontro){
                res = max(res, tot);
                tot = 0;
                encontro = false;
            }
        }
        int primera = 0;
        for (int i = 1; i <= n; i++){
            if(colores[i] == 'g'){
                primera = i;
                break;
            }
        }

        if(encontro){
            int val = n - ult;
            val = val + primera;
            res = max(res, val);
        }
        cout << res << "\n";
    }

    return 0;
}