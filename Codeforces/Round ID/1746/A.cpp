#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[105];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        for (int  i = 1; i <= n; i++) cin >> nums[i];

        bool tiene = false;
        for (int i = 1; i <= n; i++){
            if(nums[i] == 1) tiene = true;
        }
        if(!tiene){
            cout << "NO";
        }else{
            cout << "YES";
        }
        cout << "\n";
    }

    return 0;
}