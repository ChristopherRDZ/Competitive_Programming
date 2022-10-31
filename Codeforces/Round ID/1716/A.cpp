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
        int n;
        cin >> n;

        if(n % 3 == 0){
            cout << n / 3;
        }else{
            if(n == 1) cout << 2;
            if(n == 2) cout << 1;
            if(n == 4) cout << 2;
            if(n == 5) cout << 2;
            if(n == 7) cout << 3;
            if(n == 8) cout << 3;
            if(n == 10) cout << 4;
            if(n > 10){
                int tot = n / 3 + 1;
                cout << tot;
            }
        }
        cout << "\n";
    }

    return 0;
}