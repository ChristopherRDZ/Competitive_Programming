/// Problem Link: https://omegaup.com/arena/problem/Bajo-el-Volcan
/// dfs problem

#include <iostream>

using namespace std;

int n, m, f, c;
int numeros[1002][1002];
char mapa[1002][1002];

void dfs(int i, int j){
    if (i < 1 or j < 1 or i > n or j > m or mapa[i][j] == 'X'){
        return;
    }
    mapa[i][j] = 'X';
    if (numeros[i][j] > numeros[i][j + 1])
        dfs(i, j + 1);
    if (numeros[i][j] > numeros[i][j - 1])
        dfs(i, j - 1);
    if (numeros[i][j] > numeros[i + 1][j])
        dfs(i + 1, j);
    if (numeros[i][j] > numeros[i - 1][j])
        dfs(i - 1, j);
    if (numeros[i][j] > numeros[i + 1][j + 1])
        dfs(i + 1, j + 1);
    if (numeros[i][j] > numeros[i - 1][j + 1])
        dfs(i - 1, j + 1);
    if (numeros[i][j] > numeros[i + 1][j - 1])
        dfs(i + 1, j - 1);
    if (numeros[i][j] > numeros[i - 1][j - 1])
        dfs(i - 1, j - 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    cin >> f >> c;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> numeros[i][j];
        }
    }
    dfs(f, c);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (mapa[i][j] == 'X'){
                cout << mapa[i][j] << " ";
            }else{
                cout << numeros[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}