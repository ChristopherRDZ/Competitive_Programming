#include <iostream>
using namespace std;
int main(){
    int t;
    string p;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> p;
        bool posible = false;
        bool f = false;
        int aux = 0;
        for (int j = 0; j < p.size(); j++){
            if (p[j] == ')' and j == 0){
                f = true;
                break;
            }
            if (p[j] == '(' and j+1 == p.size()){
                f = true;
                break;
            }
            if (p[j] == '('){
                aux++;
            }
            if (p[j] == ')'){
                aux--;
            }
            if (p[j] == '?'){
                if (aux > 0){
                    aux--;
                }else{
                    aux++;
                }
            }
        }
        if (aux == 0 and f == false){
            posible = true;
        }
        if (posible){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}