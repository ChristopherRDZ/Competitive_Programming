#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int nums[105];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> nums[i];
        }
        int res = 0;
        int aux = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (i != j){
                    aux = aux ^ nums[j];
                }
            }
            if (aux == nums[i]){
                res = nums[i];
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;

}