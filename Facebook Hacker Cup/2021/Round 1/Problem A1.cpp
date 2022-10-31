#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream entrada;
    ofstream salida;
    entrada.open("weak_typing_chapter_1_input.txt");
    salida.open("solution.txt");
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t, n, caso = 1;
    string s;
    entrada >> t;
    while (t--){
        entrada >> n;
        entrada >> s;
        int result = 0;
        bool O = false;
        bool X = false;
        for (int i = 0; i < n; i++){
            if (!O && !X){
                if (s[i] == 'O') O = true;
                if (s[i] == 'X') X = true;
                continue;
            }else{
                if (s[i] == 'O' && O) continue;
                if (s[i] == 'O' && !O && X){
                    result++;
                    O = true;
                    X = false;
                }
                if (s[i] == 'X' && X) continue;
                if (s[i] == 'X' && !X && O){
                    result++;
                    O = false;
                    X = true;
                }
            }
        }
        salida << "Case #" << caso++ << ": " << result << "\n";
    }
    return 0;
}
