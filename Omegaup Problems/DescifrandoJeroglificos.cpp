/// Problem Link: https://omegaup.com/arena/problem/jeroglificos
/// Implementation Problem

#include <bits/stdc++.h>

using namespace std;

char cero[6][6];
char uno[6][6];
char dos[6][6];
char tres[6][6];
char cuatro[6][6];
char cinco[6][6];
char seis[6][6];
char siete[6][6];
char ocho[6][6];
char nueve[6][6];
char avanzar[6][6];
char girar_derecha[6][6];
char girar_izquierda[6][6];
char fin[6][6];
char jeroglifico[6][1002];
int numero[3];
const int v = 6;
const int jer = 1002;


bool verificar (char arre[v][v], char jero[v][jer], int pos_i ){
    int a = pos_i, b = pos_i;
    for (int i=0;i<5;i++){
        a = b;
        for (int j=0;j<5;j++){
            if (arre[i][j]!=jero[i][a]){
                return false;
            }else{
                a++;
            }
        }
    }
    return true;
}

int digito (int arre[]){
    int valor = 0;
    int d_1 = arre[1];
    int d_2 = arre[2];
    valor = (d_1 * 10) + d_2;
    return valor;
}

int vuelta (int der, int izq){
    int direccion = 0;
    int de = der, iz = izq;
    de = de % 4;
    iz = iz % 4;
    if (de == 0 && iz == 0){
        direccion = 0;
    }
    if (de == 1)
        direccion = 1;
    if (de == 2)
        direccion = 2;
    if (de == 3)
        direccion = 3;
    if (iz == 1)
        direccion = 3;
    if (iz == 2)
        direccion = 2;
    if (iz == 3)
        direccion = 1;

    return direccion;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string linea1, linea2, linea3, linea4, linea5;
    int t_j = 0, horizontal = 0, vertical = 0;
    int ini = 0, g_d = 0, g_i = 0;
    int dig = 0;
    int n = 0;
    int lugar = 0;
    for (int i=0;i<14;i++){
        for (int x=0;x<5;x++){
            for (int y=0;y<5;y++){
                if (i == 0)
                    cin >> cero[x][y];
                if (i == 1)
                    cin >> uno[x][y];
                if (i == 2)
                    cin >> dos[x][y];
                if (i == 3)
                    cin >> tres[x][y];
                if (i == 4)
                    cin >> cuatro[x][y];
                if (i == 5)
                    cin >> cinco[x][y];
                if (i == 6)
                    cin >> seis[x][y];
                if (i == 7)
                    cin >> siete[x][y];
                if (i == 8)
                    cin >> ocho[x][y];
                if (i == 9)
                    cin >> nueve[x][y];
                if (i == 10)
                    cin >> avanzar[x][y];
                if (i == 11)
                    cin >> girar_derecha[x][y];
                if (i == 12)
                    cin >> girar_izquierda[x][y];
                if (i == 13)
                    cin >> fin[x][y];
            }
        }
    }
    cin >> linea1;
    cin >> linea2;
    cin >> linea3;
    cin >> linea4;
    cin >> linea5;
    t_j = linea1.size() - 1;
    t_j = (t_j/5)+1;
    for (int i=0;i<5;i++){
        for (int j=0;j<=linea1.size()-1;j++){
            if (i == 0)
                jeroglifico[i][j] = linea1[j];
            if (i == 1)
                jeroglifico[i][j] = linea2[j];
            if (i == 2)
                jeroglifico[i][j] = linea3[j];
            if (i == 3)
                jeroglifico[i][j] = linea4[j];
            if (i == 4)
                jeroglifico[i][j] = linea5[j];
        }
    }
    while (1 == 1){
        if ( verificar(cero,jeroglifico, ini) == true){
            dig++;
            if (dig == 1){
                numero[dig] = 0;
            }
            if (dig == 2){
                numero[dig] = 0;
                n = digito(numero);
                lugar = vuelta(g_d,g_i);
                if (lugar == 0)
                    vertical = vertical + n;
                if (lugar == 1)
                    horizontal = horizontal + n;
                if (lugar == 2)
                    vertical = vertical - n;
                if (lugar == 3)
                    horizontal = horizontal - n;
            }
        }
        if ( verificar(uno,jeroglifico, ini) == true){
            dig++;
            if (dig == 1){
                numero[dig] = 1;
            }
            if (dig == 2){
                numero[dig] = 1;
                n = digito(numero);
                lugar = vuelta(g_d,g_i);
                if (lugar == 0)
                    vertical = vertical + n;
                if (lugar == 1)
                    horizontal = horizontal + n;
                if (lugar == 2)
                    vertical = vertical - n;
                if (lugar == 3)
                    horizontal = horizontal - n;
            }
        }
        if ( verificar(dos,jeroglifico, ini) == true){
            dig++;
            if (dig == 1){
                numero[dig] = 2;
            }
            if (dig == 2){
                numero[dig] = 2;
                n = digito(numero);
                lugar = vuelta(g_d,g_i);
                if (lugar == 0)
                    vertical = vertical + n;
                if (lugar == 1)
                    horizontal = horizontal + n;
                if (lugar == 2)
                    vertical = vertical - n;
                if (lugar == 3)
                    horizontal = horizontal - n;
            }
        }
        if ( verificar(tres,jeroglifico, ini) == true){
            dig++;
            if (dig == 1){
                numero[dig] = 3;
            }
            if (dig == 2){
                numero[dig] = 3;
                n = digito(numero);
                lugar = vuelta(g_d,g_i);
                if (lugar == 0)
                    vertical = vertical + n;
                if (lugar == 1)
                    horizontal = horizontal + n;
                if (lugar == 2)
                    vertical = vertical - n;
                if (lugar == 3)
                    horizontal = horizontal - n;
            }
        }
        if ( verificar(cuatro,jeroglifico, ini) == true){
            dig++;
            if (dig == 1){
                numero[dig] = 4;
            }
            if (dig == 2){
                numero[dig] = 4;
                n = digito(numero);
                lugar = vuelta(g_d,g_i);
                if (lugar == 0)
                    vertical = vertical + n;
                if (lugar == 1)
                    horizontal = horizontal + n;
                if (lugar == 2)
                    vertical = vertical - n;
                if (lugar == 3)
                    horizontal = horizontal - n;
            }
        }
        if ( verificar(cinco,jeroglifico, ini) == true){
            dig++;
            if (dig == 1){
                numero[dig] = 5;
            }
            if (dig == 2){
                numero[dig] = 5;
                n = digito(numero);
                lugar = vuelta(g_d,g_i);
                if (lugar == 0)
                    vertical = vertical + n;
                if (lugar == 1)
                    horizontal = horizontal + n;
                if (lugar == 2)
                    vertical = vertical - n;
                if (lugar == 3)
                    horizontal = horizontal - n;
            }
        }
        if ( verificar(seis,jeroglifico, ini) == true){
            dig++;
            if (dig == 1){
                numero[dig] = 6;
            }
            if (dig == 2){
                numero[dig] = 6;
                n = digito(numero);
                lugar = vuelta(g_d,g_i);
                if (lugar == 0)
                    vertical = vertical + n;
                if (lugar == 1)
                    horizontal = horizontal + n;
                if (lugar == 2)
                    vertical = vertical - n;
                if (lugar == 3)
                    horizontal = horizontal - n;
            }
        }
        if ( verificar(siete,jeroglifico, ini) == true){
            dig++;
            if (dig == 1){
                numero[dig] = 7;
            }
            if (dig == 2){
                numero[dig] = 7;
                n = digito(numero);
                lugar = vuelta(g_d,g_i);
                if (lugar == 0)
                    vertical = vertical + n;
                if (lugar == 1)
                    horizontal = horizontal + n;
                if (lugar == 2)
                    vertical = vertical - n;
                if (lugar == 3)
                    horizontal = horizontal - n;
            }
        }
        if ( verificar(ocho,jeroglifico, ini) == true){
            dig++;
            if (dig == 1){
                numero[dig] = 8;
            }
            if (dig == 2){
                numero[dig] = 8;
                n = digito(numero);
                lugar = vuelta(g_d,g_i);
                if (lugar == 0)
                    vertical = vertical + n;
                if (lugar == 1)
                    horizontal = horizontal + n;
                if (lugar == 2)
                    vertical = vertical - n;
                if (lugar == 3)
                    horizontal = horizontal - n;
            }
        }
        if ( verificar(nueve,jeroglifico, ini) == true){
            dig++;
            if (dig == 1){
                numero[dig] = 9;
            }
            if (dig == 2){
                numero[dig] = 9;
                n = digito(numero);
                lugar = vuelta(g_d,g_i);
                if (lugar == 0)
                    vertical = vertical + n;
                if (lugar == 1)
                    horizontal = horizontal + n;
                if (lugar == 2)
                    vertical = vertical - n;
                if (lugar == 3)
                    horizontal = horizontal - n;
            }
        }
        if ( verificar(girar_derecha,jeroglifico, ini) == true){
            if (g_i > 0){
                g_i--;
            }else{
                g_d++;
            }
        }
        if ( verificar(girar_izquierda,jeroglifico, ini) == true){
            if (g_d > 0){
                g_d--;
            }else{
                g_i++;
            }
        }
        if ( verificar(avanzar,jeroglifico, ini) == true){
            dig = 0;
        }
        if ( verificar(fin,jeroglifico, ini) == true){
            break;
        }
        ini = ini + 5;
    }
    cout << horizontal << " " << vertical;
    return 0;
}