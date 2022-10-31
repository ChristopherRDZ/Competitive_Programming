#include <bits/stdc++.h>
using namespace std;

int bits[12];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool pudo = false;
    for (int i  = 1; i <= 8; i++){
            cin >> bits[i];
            if (bits[i] == 9) pudo = true;
    }

    if(pudo) cout << "F";
    else cout << "S";
    cout << "\n";

    return 0;
}