/// Problem Link: https://omegaup.com/arena/problem/mirBacterias/
/// DP

#include <iostream>

using namespace std;

short int mapa[102][102];
int memo[102][102];
int m, n, tot;

int f (int i, int j){
    if (i == m and j == n){
        return mapa[i][j];
    }
    if (i < m and j < n){
        if (memo[i][j] == 0)
            memo[i][j] = min(mapa[i][j] + f(i + 1, j), mapa[i][j] + f(i, j + 1));
        return memo[i][j];
    }
    if (i >= m){
        if (memo[i][j] == 0)
            memo[i][j] = mapa[i][j] + f(i, j + 1);
        return memo[i][j];
    }
    if (j >= n){
        if (memo[i][j] == 0)
            memo[i][j] = mapa[i][j] + f(i + 1, j);
        return memo[i][j];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> mapa[i][j];
        }
    }
    cout << f(1,1);
    return 0;
}