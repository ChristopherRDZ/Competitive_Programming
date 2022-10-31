#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int num[200005];
ll acum_enfrente[200005];
ll acum_atras[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> num[i];
    }
    ll acum = 0;
    for (int i = 2; i <= n; i++){
        if (num[i - 1] > num[i]){
            acum += (num[i - 1] - num[i]);
        }
        acum_enfrente[i] = acum;
    }
    acum = 0;
    for (int i = n - 1; i >= 1; i--){
        if (num[i + 1] > num[i]){
            acum += (num[i + 1] - num[i]);
        }
        acum_atras[i] = acum;
    }

    for (int i = 1; i <= m; i++){
        int a, b;
        ll res = 0;
        cin >> a >> b;
        if (a > b){
            res = acum_atras[b] - acum_atras[a];
        }else{
            res = acum_enfrente[b] - acum_enfrente[a];
        }
        cout << res << "\n";
    }

    return 0;
}