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
        cin >> s;
        for (int i = 0; i < s.size(); i++){
            cub[s[i] - 'A' + 1]++;
        }
        for (int i = 1; i <= 26; i++){
            if (cub[i] > 0){
                tot += cub[i];
                tot++;
            }
            cub[i] = 0;
        }
        cout << tot;
        cout << "\n";


    }
    return 0;
}