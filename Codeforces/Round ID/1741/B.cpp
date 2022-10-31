#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        if(n == 3){
            cout << "-1";
        }else{
            if(n % 2 == 0){
                for (int i = n; i >= 1; i--) cout << i << " ";
            }else{
                int mitad = n / 2 + 1;
                for (int i = n; i > mitad; i--) cout << i << " ";
                for (int i = 1; i <= mitad; i++) cout << i << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}