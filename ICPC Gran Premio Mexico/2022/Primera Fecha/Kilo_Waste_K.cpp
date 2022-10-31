#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n, p, k;
int bolsa[52];
int dp[50102][52];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> p;
    for (int i = 1; i <= p; i++)
        cin >> bolsa[i];

    for (int i = 0; i <= 50100; i++)
        dp[i][0] = INT_MAX;

    for (int i = 1; i <= 50100; i++){
        for (int j = 1; j <= p; j++){
            int aux = i - bolsa[j];
            if (aux < 0)
                dp[i][j] = min(abs(aux), dp[i][j - 1]);
            else
                dp[i][j] = min(dp[aux][j], dp[i][j - 1]);
        }
    }

    for (int i = 1; i <= k; i++){
        cin >> n;
        int res = dp[n][p];
        cout << res << "\n";
    }
    return 0;
}