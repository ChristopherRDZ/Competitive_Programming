#include <iostream>
#include <fstream>

using namespace std;

int matriz[1000][1000];

int main()
{
    ifstream entrada;
    ofstream salida;
    entrada.open("traffic_control_input.txt");
    salida.open("solution.txt");

    int t, caso = 1, n, m , a , b;
    entrada >> t;
    while(t--){
        entrada >> n >> m >> a >> b;
        if ((n + m - 1) > a || (n + m - 1) > b){
            salida << "Case #" << caso++ << ": Impossible\n";
        }else{
            salida << "Case #" << caso++ << ": Possible\n";
            int abajo_der = a - m - (n - 2);
            int abajo_izq = b - m - (n - 2);
            for (int i = 1; i <= m; i++){
                matriz[1][i] = 1;
            }
            for (int i = 1; i <= n; i++){
                matriz[i][m] = 1;
                matriz[i][1] = 1;
            }
            matriz[n][m] = abajo_der;
            matriz[n][1] = abajo_izq;
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= m; j++){
                    if (matriz[i][j] == 0){
                        salida << 999 << " ";
                    }else{
                        salida << matriz[i][j] << " ";
                    }
                }
                salida << "\n";
            }
        }
    }
    return 0;
}
