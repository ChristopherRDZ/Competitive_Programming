/// Partial Solution

#include <bits/stdc++.h>
using namespace std;

char forest[3005][3005];

struct rocas{
    int pos_i;
    int pos_j;
};

vector <rocas> posiciones;

ifstream entrada("second_second_friend_input.txt");
ofstream salida("Solution_B_Hard.txt");

int cuenta(int i, int j){
    int res = 0;

    if(forest[i + 1][j] == '^') res++;
    if(forest[i - 1][j] == '^') res++;
    if(forest[i][j + 1] == '^') res++;
    if(forest[i][j - 1] == '^') res++;

    return res;
}

bool comprueba(int n, int m){
    for(rocas aux: posiciones){
        int i = aux.pos_i + 1, j = aux.pos_j;

        if(forest[i][j] == '^'){
            int opc1 = cuenta(i, j);
            if(opc1 < 2) forest[i][j] = '.';
        }

        i = aux.pos_i - 1;
        if(forest[i][j] == '^'){
            int opc2 = cuenta(i, j);
            if(opc2 < 2) forest[i][j] = '.';
        }

        i = aux.pos_i;
        j = aux.pos_j - 1;
        if(forest[i][j] == '^'){
            int opc3 = cuenta(i, j);
            if(opc3 < 2) forest[i][j] = '.';
        }

        j = aux.pos_j + 1;
        if(forest[i][j] == '^'){
            int opc4 = cuenta(i, j);
            if(opc4 < 2) forest[i][j] = '.';
        }

    }

    bool pudo = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(forest[i][j] == '^'){
                int auxiliar = cuenta(i, j);
                if(auxiliar < 2){
                    pudo = false;
                    break;
                }
            }
        }
        if (pudo == false) break;
    }
    return pudo;
}

void imprimir(int n, int m, int caso){
    salida << "Case #" << caso << ": Possible\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            salida << forest[i][j];
        }
        salida << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

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
                if(forest[i][j] == '#') posiciones.push_back({i, j});
            }
        }
        bool puede = true;

        if(n == 1 || m == 1)
            puede = false;

        if(cuantos == 0){
            imprimir(n, m, caso++);
        }else{
            if(puede){

                for(int i = 1; i <= n; i++){
                    for(int j = 1; j <= m; j++){
                        if(forest[i][j] == '.') forest[i][j] = '^';
                    }
                }

                bool pudo = comprueba(n, m);

                if(pudo) imprimir(n, m, caso++);
                else salida << "Case #" << caso++ << ": Impossible\n";

            }else{
                salida << "Case #" << caso++ << ": Impossible\n";
            }
        }

    }
    return 0;
}
