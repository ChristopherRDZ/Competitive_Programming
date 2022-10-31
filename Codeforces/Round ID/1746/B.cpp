#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        for (int  i = 1; i <= n; i++) cin >> nums[i];

        bool tiene = false;
        int unos = 0, ceros = 0;
        for (int i = 1; i <= n; i++){
            if(nums[i] == 1) unos++;
            if(nums[i] == 0) ceros++;
        }

        int tot = 0;
        for (int i = n; i >= 1; i--){
            if(nums[i] == 1) unos--;
            if(nums[i] == 0 && unos > 0){
                unos--;
                tot++;
            }
        }

        cout << tot;
        cout << "\n";
    }

    return 0;
}