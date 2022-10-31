#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ifstream entrada;
    ofstream salida;
    entrada.open("second_meaning_input.txt");
    salida.open("Solution_C.txt");

    int t, caso = 1;
    entrada >> t;
    while(t--){
        int n;
        entrada >> n;
        string s;
        entrada >> s;

        int guiones = 99;

        string res = ".";
        for(int i = 1; i <= guiones; i++)
            res += "-";
        res += ".";

        salida << "Case #" << caso++ << ":\n";
        for(int i = 1; i < n; i++){
            salida << res << "\n";
            guiones++;
            res = ".";
            for(int i = 1; i <= guiones; i++)
                res += "-";
            res += ".";
        }
    }


    return 0;
}
