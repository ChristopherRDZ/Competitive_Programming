#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int nums[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> nums[i];

        int res = 0;
        if (k == 1){
            for (int i = 2; i < n; i++){
                if (i % 2 == 0) res++;
            }
        }else{
            for (int i = 2; i < n; i++){
                if (nums[i] > (nums[i - 1] + nums[i + 1]))
                    res++;
            }
        }

        cout << res << "\n";
    }
    return 0;

}