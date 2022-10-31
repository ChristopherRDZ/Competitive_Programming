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
        int n, tot = 0, aux, x;
        string s;
        cin >> n >> x;

        for (int i = 1; i <= 2 * n; i++) cin >> nums[i];

        sort(nums + 1, nums + (2 * n + 1));

        aux = n;
        bool pudo = true;
        for (int i = n * 2; i >= n + 1; i--){
            if (nums[i] - nums[aux] < x){
                pudo = false;
                break;
            }
            aux--;
        }

        if (pudo) cout << "YES";
        else cout << "NO";

        cout << "\n";
    }
    return 0;
}