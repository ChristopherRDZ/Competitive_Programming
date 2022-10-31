#include <bits/stdc++.h>
using namespace std;

int cubeta_vocales[35];
int cubeta_conso[35];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ifstream entrada;
    entrada.open("consistency_chapter_1_input.txt");
    ofstream salida;
    salida.open("Solution_A.txt");

    int t;
    entrada >> t;

    int caso = 1;
    while(t--){
        string s;
        entrada >> s;
        for (int i = 0; i < s.size(); i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                cubeta_vocales[s[i] - 'A' + 1]++;
            }else{
                cubeta_conso[s[i] - 'A' + 1]++;
            }
        }
        int res_voca = 0, ind_v = 0;
        int res_cons = 0, ind_c = 0;
        for(int i = 1; i <= 30; i++){
            if(cubeta_vocales[i] > 0){
                if(cubeta_vocales[i] > res_voca){
                    res_voca = cubeta_vocales[i];
                    ind_v = i;
                }
            }
            if(cubeta_conso[i] > 0){
                if(cubeta_conso[i] > res_cons){
                    ind_c = i;
                    res_cons = cubeta_conso[i];
                }
            }
        }

        int opc_1 = 0, opc_2 = 0;
        for(int i = 1; i <= 30; i++){
            if(ind_v != i){
                if(cubeta_conso[i] > 0)
                    opc_1 += cubeta_conso[i];
                if(cubeta_vocales[i] > 0)
                    opc_1 += (cubeta_vocales[i] * 2);
            }
        }
        for(int i = 1; i <= 30; i++){
            if(ind_c != i){
                if(cubeta_conso[i] > 0)
                    opc_2 = opc_2 + (cubeta_conso[i] * 2);
                if(cubeta_vocales[i] > 0)
                    opc_2 += cubeta_vocales[i];
            }
            cubeta_conso[i] = 0;
            cubeta_vocales[i] = 0;
        }
        int respuesta = min(opc_1, opc_2);
        salida << "Case #" << caso << ": " << respuesta;
        caso++;
        salida << "\n";
    }
    return 0;
}
