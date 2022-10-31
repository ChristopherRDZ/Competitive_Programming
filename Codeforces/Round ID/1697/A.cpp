#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int num[1002];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        int aux = m;
        int tot = 0;
        for (int i = 1; i <= n; i++) cin >> num[i];
        for (int i = 1; i <= n; i++){
            if (aux < num[i]){
                int res = num[i] - aux;
                tot += res;
                aux += res;
            }
            aux -= num[i];
        }
        cout << tot;
        cout << "\n";
    }
    return 0;
}