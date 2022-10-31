#include <bits/stdc++.h>
using namespace std;

char forest[105][105];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ifstream entrada;
    entrada.open("second_friend_input.txt");
    ofstream salida;
    salida.open("Solution_B.txt");

    int t, caso = 1;
    entrada >> t;

    while(t--){
        int n, m;
        entrada >> n >> m;

        int cuantos = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                entrada >> forest[i][j];
                if(forest[i][j] == '^') cuantos++;
            }
        }
        bool puede = true;

        if(n == 1 || m == 1)
            puede = false;

        if(cuantos == 0){
            salida << "Case #" << caso++ << ": Possible\n";
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    salida << forest[i][j];
                }
                salida << "\n";
            }
        }else{
            if(puede){
                salida << "Case #" << caso++ << ": Possible\n";
                for(int i = 1; i <= n; i++){
                    for (int j = 1; j <= m; j++){
                        salida << '^';
                    }
                    salida << "\n";
                }
            }else{
                salida << "Case #" << caso++ << ": Impossible\n";
            }
        }

    }
    return 0;
}
