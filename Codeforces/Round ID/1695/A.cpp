#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int tab[50][50];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        long long int tot = 0;
        string s;
        int n, m;
        cin >> n >> m;
        int maxi = INT_MIN;
        int pos_i, pos_j;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> tab[i][j];
                if (tab[i][j] > maxi){
                    maxi = tab[i][j];
                    pos_i = i;
                    pos_j = j;
                }
            }
        }

        int aux_1 = max(n - (pos_i - 1), pos_i);
        int aux_2 = max(m - (pos_j - 1), pos_j);
        tot = aux_1 * aux_2;
        cout << tot;

        cout << "\n";
    }
    return 0;
}