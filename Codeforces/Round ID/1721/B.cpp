#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int table[10002][1002];
int n, m, a, b, d;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> a >> b >> d;

        int aux_f = b - 1, aux_c = a - 1;
        int aux_ft = m - b, aux_ct = n - a;

        if((aux_f > d && aux_ct > d) || (aux_c > d && aux_ft > d)){
            cout << (n - 1) + (m - 1);
        }else{
            cout << "-1";
        }
        cout << "\n";


    }

    return 0;
}