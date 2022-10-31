#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];
int cub[40];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, tot = 0, aux;
        string s;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> nums[i];
        }

        for (int i = 1; i <= n; i++){
            int aux;
            cin >> aux;
            for (int j = 1; j <= aux; j++){
                char c;
                cin >> c;
                if (c == 'U'){
                    nums[i]--;
                    if (nums[i] < 0) nums[i] = 9;
                }
                if (c == 'D'){
                    nums[i]++;
                    if (nums[i] > 9) nums[i] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++) cout << nums[i] << " ";

        cout << "\n";


    }
    return 0;
}