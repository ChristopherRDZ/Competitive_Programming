/// Problem Link: https://omegaup.com/arena/problem/The-Castle/
/// bfs/dfs (IOI - 1994 / easier version)

#include <bits/stdc++.h>
using namespace std;

queue < pair <int, int > > grafo;

int n, m;
int tablero[52][52];
int visited[52][52];

void agregarArriba(int i, int j, int valor){
    pair <int, int > aux = {i - 1, j};
    if(valor % 4 == 0 || valor % 4 == 1)
        grafo.push(aux);
}

void agregarAbajo(int i, int j, int valor){
    pair <int, int> aux = {i + 1, j};
    if(valor >= 0 && valor <= 7)
        grafo.push(aux);
}

void agregarDer(int i, int j, int valor){
    pair <int, int> aux = {i, j + 1};
    if((valor >= 0 && valor <= 3) || (valor >= 8 && valor <= 11))
        grafo.push(aux);
}

void agregarIzq(int i, int j, int valor){
    pair <int, int> aux = {i, j - 1};
    if(valor % 2 == 0)
        grafo.push(aux);
}

int bfs(){
    int res = 0;
    while(!grafo.empty()){
        pair <int, int> aux = grafo.front();
        grafo.pop();
        int i = aux.first, j = aux.second;
        if(!visited[i][j]){
            visited[i][j] = true;
            if((i >= 1 && i <= n) && (j >= 1 && j <= m)){
                res++;
                agregarArriba(i, j, tablero[i][j]);
                agregarAbajo(i, j, tablero[i][j]);
                agregarDer(i, j, tablero[i][j]);
                agregarIzq(i, j, tablero[i][j]);
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> tablero[i][j];

    int cuantos = 0, mejor = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!visited[i][j]){
                cuantos++;
                pair <int, int> aux = {i, j};
                grafo.push(aux);
                int tot = bfs();
                if(tot > mejor) mejor = tot;
            }
        }
    }
    cout << cuantos << "\n" << mejor;
    return 0;
} 