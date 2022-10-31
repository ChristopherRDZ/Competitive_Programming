/// Problem Link: https://omegaup.com/arena/problem/IOI-2000---Palindromo
/// DP with memory optimization

#include <bits/stdc++.h>
using namespace std;

int n;
char s[5002];
int dp[4][5002];
//int dp[5002][5002];
//int memo[5002][5002];


/*
//recursive
int f (int i, int j){
    if (i == j) return 0;
    if (i > j) return 0;
    if (s[i] != s[j]){
        return min(f(i, j - 1) + 1, f(i + 1, j) + 1);
    } 
    return f(i + 1, j - 1);
}

//memorization
int f(int i, int j){
    if (i == j or i > j){
        memo[i][j] = 0;
    }else{
        if (memo[i][j] == -1){
            if (s[i] != s[j]){
                memo[i][j] = min(f(i, j - 1) + 1, f(i + 1, j) + 1);
            }else{
                memo[i][j] = f(i + 1, j - 1);
            }
        }
    }
    return memo[i][j];
}

// iterative
for (int i = n; i >= 1; i--){
    for  (int j = 1; j <= n; j++){
        if (i > j or i == j){
            dp[i][j] = 0;
            continue;
        }
        if (s[i] != s[j]){
            dp[i][j] = min(dp[i][j - 1] + 1, dp[i + 1][j] + 1);
        }else{
            dp[i][j] = dp[i + 1][j - 1];
        }
    }
}
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];

    for (int i = n; i >= 1; i--){
        for  (int j = 1; j <= n; j++){
            //cout << dp[i % 2][j] << " ";
            if (i > j or i == j){
                dp[i % 2][j] = 0;
                continue;
            }
            if (s[i] != s[j]){
                dp[i % 2][j] = min(dp[i % 2][j - 1] + 1, dp[(i + 1) % 2][j] + 1);
            }else{
                dp[i % 2][j] = dp[(i + 1) % 2][j - 1];
            }
        }
        //cout << "\n";
    }
    cout << dp[1][n];
    return 0;
}