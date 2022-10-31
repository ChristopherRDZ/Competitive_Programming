#include <bits/stdc++.h>
#include <vector>
#include <fstream>

using namespace std;

vector <int> grafo[100002];
int pesos[102];
long long int totales[102];
bool visited[102];
bool bloqueados[102];

void dfs(int nodo, int anterior){
    visited[nodo] = true;
    totales[nodo] += pesos[nodo] + totales[anterior];
    for (int x: grafo[nodo]){
        if (x != anterior and !visited[x]){
            dfs(x, nodo);
        }
    }
}

void dfs_inversa(int nodo, int anterior){
    if (nodo == 1) return;
    bloqueados[nodo] = true;
    visited[nodo] = true;
    for (int x: grafo[nodo]){
        if (x != anterior and !visited[x]){
            dfs_inversa(x, nodo);
        }
    }
}

void dfs_ult(int nodo, int anterior){
    visited[nodo] = true;
    totales[nodo] += pesos[nodo] + totales[anterior];
    for (int x: grafo[nodo]){
        if (x != anterior and !visited[x] and !bloqueados[x]){
            dfs_ult(x, nodo);
        }
    }
}

int main()
{
    ifstream entrada;
    ofstream salida;
    entrada.open("gold_mine_chapter_1_input.txt");
    salida.open("solution_example.txt");
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, x, y, caso = 1;
    entrada >> t;
    while (t--){
        int n;
        entrada >> n;
        for (int i = 1; i <= n; i++) entrada >> pesos[i];
        for (int i = 1; i < n; i++){
            entrada >> x >> y;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }
        dfs(1, 0);
        long long int aux, mayor = 0, res = 0;
        for (int i = 1; i <= n; i++){
            if (totales[i] > mayor){
                mayor = totales[i];
                aux = i;
            }
            visited[i] = false;
        }
        res = mayor;
        dfs_inversa(aux, 0);
        for (int i = 1; i <= n; i++){
            totales[i] = 0;
            visited[i] = false;
        }
        dfs_ult(1, 0);
        mayor = 0;
        for (int i = 1; i <= n; i++){
            if (totales[i] > mayor){
                mayor = totales[i];
            }
            totales[i] = 0;
            visited[i] = false;
            bloqueados[i] = false;
            grafo[i].clear();
        }
        res += mayor - pesos[1];
        salida << "Case #" << caso++ << ": " << res << "\n";
    }
    return 0;
}

