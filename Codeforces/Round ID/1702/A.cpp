#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[205];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, m, tot = 0;
        string s;

        cin >> n;

        int pos = 0;
        int pot = 1;
        for (int i = 1; i <= 10; i++){
            nums[i] = pot;
            pot *= 10;
        }

        for (int i = 1; i <= 10; i++){
            if (nums[i] > n){
                tot = n - nums[i - 1];
                break;
            }
            if (nums[i] == n){
                tot = 0;
                break;
            }
        }

        cout << tot;
        cout << "\n";
    }
    return 0;
}