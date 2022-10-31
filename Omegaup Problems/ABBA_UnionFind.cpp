/// Problem Link: https://omegaup.com/arena/problem/abba
/// UnionFind

// problema de omegaup

#include <bits/stdc++.h>
using namespace std;

int Setsize[130];
int link[130];
int tot;

void init(){
    for (int i = 'a'; i <= 'z'; i++){
        link[i] = i;
        Setsize[i] = 1;
    }
}

int find(int u){
    if (link[u] == u){
        return u;
    }else{
        link[u] = find(link[u]);
        return link[u];
    }
}

void unite(int u, int v){
    u = find(u);
    v = find(v);
    if (u != v){
        if (Setsize[v] > Setsize[u]) swap(u, v);
        Setsize[u] += Setsize[v];
        link[v] = u;
        tot++; 
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    int ini, fin;
    cin >> s;
    init();
    ini = 0;
    fin = s.size() - 1;
    while(ini < fin){
        unite(s[ini], s[fin]);
        ini++;
        fin--;
    }
    cout << tot;
    return 0;
}