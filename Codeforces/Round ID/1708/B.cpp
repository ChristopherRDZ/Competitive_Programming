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
        int n, l, r, tot = 0;
        cin >> n >> l >> r;

        bool pudo = true;
        for (int i = 1; i <= n; i++){
            if (l % i == 0){
                nums[i] = l;
            }else{
                int aux = l % i;
                int a = l + (i - aux);
                if (a <= r){
                    nums[i] = a;
                }else{
                    pudo = false;
                    break;
                }
            }
        }
        if (pudo){
            cout << "YES\n";
            for (int i = 1; i <= n; i++){
                cout << nums[i] << " ";
            }
        }else{
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}