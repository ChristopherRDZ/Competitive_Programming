/// Problem Link: https://omegaup.com/arena/problem/writing/
/// Sliding windows (IOI 2006)

#include <bits/stdc++.h>

using namespace std;

int arreglo[125];
int arreglo_posible[125];
string sub_cadena,cadena;
int tamanio_subcadena,respuesta,tamanio_cadena,iterador_inicio,iterador_final;

void convierte(){
    for(int x=0;x<tamanio_subcadena;x++){
        arreglo[sub_cadena[x]-64]++;
        arreglo_posible[cadena[x]-64]++;
    }
}

bool compara(){
    for(int x=0;x<=123;x++){
        if(arreglo_posible[x]!=arreglo[x]){
            return false;
        }
    }
    return true;
}

int main()

{

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>tamanio_subcadena>>tamanio_cadena;
    cin>>sub_cadena>>cadena;

    convierte();

    iterador_final=tamanio_subcadena;
    while(iterador_final<=tamanio_cadena){
        if(compara()){
            respuesta++;
        }
        arreglo_posible[cadena[iterador_inicio]-64]--;
        arreglo_posible[cadena[iterador_final]-64]++;
        iterador_final++;
        iterador_inicio++;

    }

    cout<<respuesta;

    return 0;
}

