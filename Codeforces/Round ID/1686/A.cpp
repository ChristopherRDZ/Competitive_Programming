#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

float arre[1002];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        float n, sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arre[i];
            sum += arre[i];
        }
        bool puede = false;
        for (int i = 1; i <= n; i++){
            float tot = sum - arre[i];
            tot = tot / (n - 1);
            if (tot == arre[i]) puede = true;
        }
        if (puede) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}