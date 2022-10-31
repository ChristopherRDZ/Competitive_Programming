/// Problem Link:  https://omegaup.com/arena/problem/gato-familias-ratones
/// DP

#include <stdio.h>

int num[105];
int dp[2][1000005];
int n, capacidad;

int main()
{

    scanf("%d %d", &n, &capacidad);
    for (int i = 1; i <= n; i++) scanf("%d", &num[i]);

    for (int i = n; i >= 1; i--){
        for (int j = num[i]; j <= capacidad; j++){
            int aux = j - num[i];
            int res = dp[(i + 1) % 2][aux] + num[i];
            if (dp[(i + 1) % 2][j] > res) res = dp[(i + 1) % 2][j];
            dp[i % 2][j] = res;
        }
    }

    printf("%d", dp[1 % 2][capacidad]);
    return 0;
}