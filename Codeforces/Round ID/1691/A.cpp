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
        int n, par = 0, impar = 0, aux;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> aux;
            if (aux & 1) impar++;
            else par++;
        }
        cout << min(impar, par) << "\n";
    }
    return 0;
}