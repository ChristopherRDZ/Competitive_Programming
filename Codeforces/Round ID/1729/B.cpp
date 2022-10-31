#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

char arre[55];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arre[i];

        int ini = n;
        string res = "";
        while(ini >= 1){
            int tot = 0, aux;
            if(arre[ini] == '0'){
                ini--;
                tot = arre[ini] - '0';
                ini--;
                aux = arre[ini] - '0';
                aux = aux * 10 + tot;
                char letra = aux + 'a' - 1;
                res += letra;
                ini--;
            }else{
                tot = arre[ini] - '0';
                char letra = tot + 'a' - 1;
                res += letra;
                ini--;
            }
        }
        for (int i = res.size() - 1; i >= 0; i--)
            cout << res[i];

        cout << "\n";
    }
    return 0;
}