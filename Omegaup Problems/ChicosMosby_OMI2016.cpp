/// Problem Link: https://omegaup.com/arena/problem/OMI-2016-Chicos-Mosby
/// OMI 2016

#include <iostream>

using namespace std;

int main()
{
    int filas, columnas, modulo, minimo, maximo, a, minutos = 0;
    cin >> filas >> columnas;
    modulo = 1;
    while ( modulo != 0){
        minimo = min(filas, columnas);
        maximo = max(filas, columnas);
        if (minimo == filas){
            a = maximo / minimo;
            modulo = maximo % minimo;
            columnas = modulo;
        }else{
            a = maximo / minimo;
            modulo = maximo % minimo;
            filas = modulo;
        }
        minutos += a;
    }
    cout << minutos;
    return 0;
}