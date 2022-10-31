/// Problem Link: https://omegaup.com/arena/problem/metro
/// UnionFind + Kruskal algorithm

// problema de omegaup

#include <bits/stdc++.h>
using namespace std;

int link[30005];
int Setsize[30005];
int n, m;
int nums, total;

struct arista{
    int a;
    int b;
    int p;
};

const bool operator <(const arista&c, const arista&d){
    return c.p > d.p;
}

priority_queue <arista> q;

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

void unite(int u, int v, int peso){
    u = root(u);
    v = root(v);
    if (u != v){
        if (Setsize[v] > Setsize[u]) swap(u, v);
        Setsize[u] += Setsize[v];
        link[v] = u;
        nums++;
        total += peso;
    }
}

void kruskal(){
    arista aux;
    while(!q.empty()){
        aux = q.top();
        q.pop();
        unite(aux.a, aux.b, aux.p);
        if (nums == n - 1) break;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    init();
    arista aux;
    for (int i = 1; i <= m; i++){
        cin >> aux.a >> aux.b >> aux.p;
        q.push(aux);
    }
    kruskal();
    cout << total;
    return 0;
}