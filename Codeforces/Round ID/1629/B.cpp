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
        int l, r, k;
        cin >> l >> r >> k;

        if (l == r && l != 1){
            cout << "YES";
        }else{
            int tot = r / 2;
            if (l % 2 == 0) tot = tot - (l / 2 - 1);
            else tot = tot - (l / 2);

            int tot_2 = (r - l + 1) - tot;

            tot_2 = tot_2 - k;
            if (tot_2 <= 0){
                cout << "YES";
            }else{
                cout << "NO";
            }

        }
        cout << "\n";

    }
    return 0;
}