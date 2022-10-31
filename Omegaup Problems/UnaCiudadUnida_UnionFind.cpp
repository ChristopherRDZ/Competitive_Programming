/// Problem Link:  https://omegaup.com/arena/problem/Una-ciudad-unida
/// UnionFind 

// problema de omegaup

#include <bits/stdc++.h>
using namespace std;

int link[2005];
int Setsize[2005];
int tot[2005];
int n, m;

void init(){
    for (int i = 1; i <= n; i++){
        link[i] = i;
        Setsize[i] = 1;
    }
}

int root(int u){
    if (link[u] == u){
        return u;
    }else{
        link[u] = root(link[u]);
        return link[u];
    }
}

void unite(int u, int v){
    u = root(u);
    v = root(v);
    if (u != v){
        if (Setsize[v] > Setsize[u]) swap(u, v);
        Setsize[u] += Setsize[v];
        link[v] = u;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int a, b;
    int total = n * (n - 1) / 2; // formas posibles
    int aux;
    init();
    for (int i = 1; i <= m; i++){
        cin >> a >> b;
        unite(a, b);
    }
    for (int i = 1; i <= n; i++){
        tot[root(i)]++;
    }
    for (int i = 1; i <= n; i++){
        if (tot[i] > 0){
            aux = tot[i] * (tot[i] - 1) / 2;
            total -= aux;
        }
    }
    cout << total;
    return 0;
}