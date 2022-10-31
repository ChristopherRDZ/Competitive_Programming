#include <bits/stdc++.h>
using namespace std;

int cubeta[105];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ifstream entrada;
    entrada.open("second_hands_input.txt");
    ofstream salida;
    salida.open("Solution_A.txt");

    int t, caso = 1;
    entrada >> t;

    while(t--){

        int n, k;
        entrada >> n >> k;
        for(int i = 1; i <= n; i++){
            int x;
            entrada >> x;
            cubeta[x]++;
        }

        bool puede = true;
        for(int i = 1; i <= 102; i++){
            if(cubeta[i] > 2) puede = false;
            cubeta[i] = 0;
        }
        if(k * 2 < n) puede = false;

        salida << "Case #" << caso++ << ": ";

        if(puede) salida << "YES";
        else salida << "NO";

        salida << "\n";

    }
    return 0;
}
