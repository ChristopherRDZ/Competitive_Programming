/// Problem Link: https://omegaup.com/arena/problem/Subsecmoncre
/// DP (EasyVersion)

#include <bits/stdc++.h>

using namespace std;

int numeros[1002];
int dp[1002];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> numeros[i];
    }
    numeros[0] = -1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (numeros[i] > numeros[j - 1])
                dp[i] = max(1 + dp[j - 1], dp[i]);
        }
        if (dp[i] > m) m = dp[i];
    }
    cout << m;
    return 0;
}