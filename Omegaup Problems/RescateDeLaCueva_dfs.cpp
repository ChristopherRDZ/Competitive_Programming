/// Problem Link: https://omegaup.com/arena/problem/cueva
/// dfs (One of my favorite problems)

#include <stdio.h>
#include <vector>
using namespace std;

vector <int> arbol[1000001];
int ini[1000001];
int fin[1000001];
int tiempo = 1;

void precalculo(int &nodo){
        ini[nodo] = tiempo++;
        for (int i = 0; i < arbol[nodo].size(); i++){
            if(ini[arbol[nodo][i]] == 0)
                precalculo(arbol[nodo][i]);
        }
        arbol[nodo].clear();
        fin[nodo] = tiempo - 1;
}

int main()

{

    int n, q, a, b;
    scanf("%d %d", &n, &q);

    for (int i = 1; i < n; i++){
        scanf("%d %d", &a, &b);
        arbol[a].push_back(b);
        arbol[b].push_back(a);
    }

    int var = 1;
    precalculo(var);
    for (int i = 1; i <= q; i++){
        scanf("%d %d", &a, &b);
      
        if (ini[a] <= ini[b] && fin[a] >= ini[b]) printf("0\n");
        else printf("1\n");
    }

    return 0;
}