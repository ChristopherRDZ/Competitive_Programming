/// Problem Link: https://omegaup.com/arena/problem/OMI2018-Convertidor
/// OMI 2018

#include <iostream>
#include <math.h>

using namespace std;

int letras (char x){
    int valor = x - 'A' + 1;
    return valor;

}

char numeros (long long int n){
    char letra = n + 'A' - 1;
    return letra;
}

char respuesta[102];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    short int convertir;
    long long int numero, residuo, aux;
    string s;

    cin >> convertir;
    if (convertir == 0){
        cin >> numero;
        if (numero <=26){
            cout << numeros(numero);
        }else{
            aux = 0;
            while (numero > 0){
                residuo = numero % 26;
                numero = numero / 26;
                if (residuo == 0){
                    numero--;
                    residuo = 26;
                    respuesta[aux] = numeros(residuo);
                    aux++;
                }else{
                    respuesta[aux] = numeros(residuo);
                    aux++;
                }
            }

            aux = aux - 1;
            for (int i=aux;i>=0;i--){
                cout << respuesta[i];
            }
        }
    }else{
        long long int tamano, potencia, t, res, tot = 0, a1;
        char a;

        cin >> s;
        tamano = s.size();
        t = tamano;

        if (tamano <= 1){
            a = s[0];
            cout << letras(a);
        }else{
            const long long int v_n = 26;
            t = s.size();
            tot = 0;
            res = 0;
            for (int i=0;i<tamano;i++){
                potencia = (t - 1);
                a = s[i];
                a1 = letras(a);
                if (potencia >= 1){
                    res = 1;
                    for (int i=1;i<=potencia;i++){
                        res = res * 26;
                    }
                }else{
                    res = 1;
                }
                res = a1 * res;
                tot += res;
                t--;
            }
            cout << tot;
        }
    }
    return 0;
}