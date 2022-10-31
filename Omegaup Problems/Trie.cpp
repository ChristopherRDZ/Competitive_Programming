/// Problem Link: https://omegaup.com/arena/problem/ppd/
/// DATA STRUCTURE TRIE

//Estructura de datos trie 
//Programa que dada una lista de palabras
//encuentra cuantas de ellas empiezan por un prefijo dado
#include <bits/stdc++.h>
using namespace std;

struct nodo{
    int cuantos;
    nodo *letras[28];
};

bool first;
string x;

void insertar(nodo *& raiz, int pos, int tam){
    if (!first) raiz->cuantos++;

    if (pos == tam) return;

    int let = x[pos] - 'a' + 1;
    if (raiz->letras[let] == NULL){
        first = false;
        nodo *temp = new nodo();
        temp->cuantos = 0;
        raiz->letras[let] = temp;
        insertar(raiz->letras[let], pos + 1, tam);
    }else{
        first = false;
        insertar(raiz->letras[let], pos + 1, tam);
    }
}

int buscar(nodo *&raiz, int pos, int tam){
    if (raiz == NULL) return 0;
    if (pos == tam) return raiz->cuantos;

    int sig = x[pos] - 'a' + 1;
    int aux = buscar(raiz->letras[sig], pos + 1, tam);
    int res = min(raiz->cuantos, aux);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    nodo *raiz = new nodo();
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> x;

        int tam = x.size();
        first = true;
        insertar(raiz, 0, tam);
    }

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++){
        cin >> x;

        int tam = x.size();
        int primera = x[0] - 'a' + 1;
        int res = buscar(raiz->letras[primera], 1, tam);

        cout << res << " ";
    }
    return 0;
}