#include <bits/stdc++.h>
using namespace std;

struct dato{
    int gasta;
    int ram;
};


bool operator <(const dato &a, const dato &b){
    if (a.gasta < b.gasta) return true;
    return false;
}

dato componente[1005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test;
    cin >> test;

    while(test--){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> componente[i].gasta;
        for (int i = 1; i <= n; i++) cin >> componente[i].ram;
        sort(componente + 1, componente + n + 1);
        for (int i = 1; i <= n; i++){
            if (componente[i].gasta <= k) k += componente[i].ram;
        }

        cout << k;
        cout << "\n";

    }
    return 0;
}