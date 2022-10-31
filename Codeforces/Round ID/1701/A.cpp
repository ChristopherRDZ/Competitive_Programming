#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int a, b, c, d, tot = 20;
        cin >> a >> b >> c >> d;

        int aux = 0, x = 0, y = 0, z = 0;

        if (b == 1 || c == 1 || a == 1) aux = 1;
        if (d == 1) aux++;

        if (a == 1 || d == 1 || b == 1) x = 1;
        if (c == 1) x++;

        if (a == 1 || d == 1 || c == 1) y = 1;
        if (b == 1) y++;

        if (c == 1 || b == 1 || d == 1) z = 1;
        if (a == 1) z++;

        if (x < tot) tot = x;
        if (aux < tot) tot = aux;
        if (y < tot) tot = y;
        if (z < tot) tot = z;

        cout << tot << "\n";
    }
    return 0;
}