#include <bits/stdc++.h>
using namespace std;

char palabra[102];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, aux, aux_2;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> n;
        for (int j = 1; j <= n; j++){
            cin >> palabra[j];
        } 
        aux = 0;
        aux_2 = n;
        while (1 == 1){
            if (palabra[aux_2] == ')'){
                aux++;
                aux_2--;
            }else{
                break;
            }
        }
        if (aux > aux_2){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
   return 0;     
}