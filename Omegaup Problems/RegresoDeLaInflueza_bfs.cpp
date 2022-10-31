/// Problem Link: https://omegaup.com/arena/problem/El-regreso-de-la-Influenza-AH1N1
/// BFS 

#include <iostream>

using namespace std;

char mapa[1002][1002];
int F, C, contador;

void bfs(int i, int j){
    if (mapa[i][j] == '.' or i < 1 or j < 1 or i > F or j > C){
        return;
    }
    mapa[i][j] = '.';
    bfs(i - 1, j);
    bfs(i + 1, j);
    bfs(i, j + 1);
    bfs(i, j - 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> F >> C;
    for (int i = 1; i <= F; i++){
        for (int j = 1; j <= C; j++){
            cin >> mapa[i][j];
        }
    }
    for (int i = 1; i <= F; i++){
        for (int j = 1; j <= C; j++){
            if (mapa[i][j] == 'x')
                bfs(i, j);
        }
    }
    for (int i = 1; i <= F; i++){
        for (int j = 1; j <= C; j++){
            if (mapa[i][j] == 'l'){
                contador++;
                bfs(i, j);
            }
        }
    }
    if (contador >= 1)
        cout << contador - 1;
    if (contador <= 0){
        cout << contador;
    }
    return 0;
}