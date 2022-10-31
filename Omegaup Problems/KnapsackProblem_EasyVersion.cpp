/// Problem Link:  https://omegaup.com/arena/problem/El-problema-de-la-mochila-d
/// Dynamic programming (Knapsack Problem)

#include <iostream>

using namespace std;

int valor[1002];
int peso[1002];
int memo[1002][502];

int f(int i, int M){
    if (M < 0 or i <= 0){
        return 0;
    }
    if (peso[i] <= M ){
        if (memo[i][M] == -1){
            memo[i][M] = max(valor[i] + f(i - 1, M - peso[i]), f(i - 1, M));
        }
    }
    if (peso[i] > M){
        if (memo[i][M] == -1){
            memo[i][M] = f(i - 1, M);
        }
    }
    return memo[i][M];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> peso[i] >> valor[i];
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            memo[i][j] = -1;
        }
    }
    cout << f(n, m);
    return 0;
}