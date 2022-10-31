/// Problem Link: https://omegaup.com/arena/problem/Enredados/
/// Binary Indexeed tree (BIT)

#include <bits/stdc++.h>
#define MAX 1500005
using namespace std;

int fijo[MAX];
int bit[MAX];
int n;
int tam;

long long int query(int indice){
    long long int suma=0;
    while(indice > 0){
        suma += bit[indice];
        indice -= (indice & (-indice));
    }
    return suma;
}

long long int query_2(int l,int r){
    return(query(r) - query(l - 1));
}

void update(int i, int valor, int a){
    while(i <= a){
        bit[i] += (long long int)valor;
        i += (i & (-i));
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int aux;
    tam = n / 2;
    long long int total = 0;
    for (int i = 1; i <= tam; i++){
        cin >> aux;
        fijo[aux] = i;
    }
    for (int i = 1; i <= tam; i++){
        cin >> aux;
        total += query_2(fijo[aux] + 1, tam);
        update(fijo[aux], 1, tam);
    }
    cout << total;
    return 0;
}