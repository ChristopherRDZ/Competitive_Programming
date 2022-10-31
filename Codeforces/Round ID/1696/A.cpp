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
        int n, z;
        cin >> n >> z;
        int maxi = -1;
        fr(n){
            cin >> nums[i];
            int res = nums[i] | z;
            if (res > maxi) maxi = res;
        }
        cout << maxi;
        cout << "\n";
    }
    return 0;
}