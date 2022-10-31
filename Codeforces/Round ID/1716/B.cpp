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

        if (n == 2){
            cout << 2 << "\n";
            cout << 1 << " " << 2 << "\n";
            cout << 2 << " " << 1 << "\n";
        }
        if(n == 3){
            cout << 3 << "\n";
            cout << 1 << " " << 2 << " " << 3 << "\n";
            cout << 3 << " " << 2 << " " << 1 << "\n";
            cout << 3 << " " << 1 << " " << 2 << "\n";
        }
        if (n > 3){
            cout << n << "\n";
            for (int i = 1; i <= n; i++) nums[i] = i;

            int a = 1, b = 2;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    cout << nums[j] << " ";
                }
                swap(nums[a], nums[b]);
                a++;
                b++;
                cout << "\n";
            }
        }
        //cout << "\n";
    }

    return 0;
}