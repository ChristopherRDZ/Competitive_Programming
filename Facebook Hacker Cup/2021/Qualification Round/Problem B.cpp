#include <iostream>
#include <fstream>

using namespace std;

char tabla[55][55];
bool vertical[52];
bool horizontal[52];
bool ocupado[52][52];

int main()
{
    ifstream entrada;
    ofstream salida;
    entrada.open("xs_and_os_input.txt");
    salida.open("solution.txt");

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t, n, caso = 1;
    entrada >> t;
    while (t--){
        entrada >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                entrada >> tabla[i][j];
                if (tabla[i][j] == 'O'){
                    vertical[j] = true;
                    horizontal[i] = true;
                }
            }
        }
        int maximo = 100000000;
        // revisamos horizontales
        int aux = 0, contador = 0;
        int x, y;
        for (int i = 1; i <= n; i++){
            if (!horizontal[i]){
                aux = 0;
                for (int j = 1; j <= n; j++){
                    if (tabla[i][j] == '.'){
                        aux++;
                        x = i;
                        y = j;
                    }
                }
                if (aux < maximo){
                    maximo = aux;
                    contador = 0;
                }
                if (aux == maximo) contador++;
                if (aux == 1){
                    ocupado[x][y] = true;
                }
            }
            horizontal[i] = false;
        }
        //revisamos verticales
        bool chale = false;
        for (int i = 1; i <= n; i++){
            if (!vertical[i]){
                aux = 0;
                chale = false;
                for (int j = 1; j <= n; j++){
                    if (tabla[j][i] == '.') aux++;
                    if (ocupado[j][i]) chale = true;
                }
                if ((chale == true and aux > 1) or (chale == false)){
                    if (aux < maximo){
                        maximo = aux;
                        contador = 0;
                    }
                    if (aux == maximo) contador++;
                }
            }
            vertical[i] = false;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                ocupado[i][j] = false;
            }
        }
        if (maximo == 100000000){
            salida << "Case #" << caso++ <<": Impossible\n";
        }else{
            salida << "Case #" << caso++ << ": " << maximo << " " << contador << "\n";
        }
    }

    return 0;
}
