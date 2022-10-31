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
        int n, tot = 0, aux;
        char a, b, c;
        cin >> a >> b >> c;

        a = tolower(a);
        b = tolower(b);
        c = tolower(c);

        if (a == 'y' && b == 'e' && c == 's')
            cout << "YES";
        else cout << "NO";

        cout << "\n";


    }
    return 0;
}