#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, res = 0, aux;
        cin >> n >> m;
        if(n == 1 || m == 1){
            if(n == 1 && m == 1){
                cout << 0;
            }else{
                if (n == 1) cout << m;
                else cout << n;
            }
        }else{
            if(n > m){
                res = (n - 1) + (m - 1);
                res = res + m;
                cout << res;
            }else{
                res = (n - 1) + (m - 1);
                res = res + n;
                cout << res;
            }
        }
        cout  << "\n";
    }

    return 0;
}