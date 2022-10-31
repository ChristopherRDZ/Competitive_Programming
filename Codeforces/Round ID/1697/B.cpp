#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

ll num[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t;
    //cin >> t;

    //while(t--){
        int n, q;
        ll tot = 0;

        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> num[i];

        sort(num + 1, num + n + 1);

        for (int i = 1; i <= n; i++){
            num[i] = num[i] + num[i - 1];
        }
        for (int i = 1; i <= q; i++){
            int x, y;
            cin >> x >> y;
            int aux = n - x;
            int agarra = aux + y;
            tot = num[agarra] - num[aux];
            cout << tot << "\n";
        }
    ///}
    return 0;
}