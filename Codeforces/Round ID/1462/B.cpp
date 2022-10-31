#include <bits/stdc++.h>
using namespace std;

char numeros[202];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> n;
        bool possible = false;
        for (int j = 1; j <= n; j++){
            cin >> numeros[j];
        }
        if (numeros[1] == '2' and numeros[n-2] == '0' and numeros[n-1] == '2' and numeros[n] == '0'){
            possible = true;
        }
        if (numeros[1] == '2' and numeros[2] == '0' and numeros[3] == '2' and numeros[n] == '0'){
            possible = true;
        }
        if (numeros[1] == '2' and numeros[2] == '0' and numeros[n-1] == '2' and numeros[n] == '0'){
            possible = true;
        }
        if (numeros[1] == '2' and numeros[2] == '0' and numeros[3] == '2' and numeros[4] == '0'){
            possible = true;
        }
         if (numeros[n-3] == '2' and numeros[n-2] == '0' and numeros[n-1] == '2' and numeros[n] == '0'){
            possible = true;
        }
        if (possible){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
   return 0; 
}