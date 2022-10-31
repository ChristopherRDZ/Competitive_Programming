#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[100005];
int cubeta[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> nums[i];
        for (int i = 1; i <= n; i++){
            int x = nums[i];
            cubeta[x]++;
        }
        int pos;
        for(int i = n; i >= 1; i--){
            if(nums[i] >= nums [i - 1]){
                cubeta[nums[i]]--;
            }else{
                pos = i;
                cubeta[nums[i]]--;
                break;
            }
        }
        for (int i = n; i >= pos; i--){
            if (cubeta[nums[i]] > 0){
                for(int j = i; j >= pos; j--){
                    cubeta[nums[j]]++;
                }
                break;
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++){
            if(cubeta[i] > 0) res++;
            cubeta[i] = 0;
        }
        cout << res << "\n";
    }

    return 0;
}