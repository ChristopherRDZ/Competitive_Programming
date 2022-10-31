/// Problem Link: https://omegaup.com/arena/problem/COMI-Parentesis/
/// Stack Implementation

#include <iostream>
#include <stdlib.h>

using namespace std;


struct nodo{
    int aux;
    nodo *siguiente;
};

void insertar(nodo *& pila, int letra){
    nodo *elemento = new nodo();
    elemento->aux = letra;
    elemento->siguiente = pila;
    pila = elemento;
    //cout << "Inserte -> " << letra << ".\n";
}

void borrar(nodo *& pila){
    nodo *auxiliar = pila;
    pila = pila->siguiente;
    //cout << "Borre -> " << auxiliar->aux << ".\n";
    delete auxiliar;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    nodo *pila = NULL; ///Creamos nuestra pila
    string s;
    cin >> s;

    int numero = 1;
    bool puede = true;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            insertar(pila, numero);
            numero++;
        }else{
            if (pila == NULL){
                puede = false;
                break;
            }else{
                numero--;
                borrar(pila);
            }
        }
    }

    if (pila != NULL) puede = false;
    if (puede) cout << "SI";
    if (!puede) cout << "NO";

    return 0;
}



