#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, tot = 0;
        string s;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> nums[i];

        int aux = nums[1];
        bool pudo = true;
        for (int i = n; i >= 2; i--){
            if (nums[i] % aux != 0) pudo = false;
        }
        if (aux == 1) pudo = true;
        if (pudo) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}