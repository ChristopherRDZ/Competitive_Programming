#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int cases, n;
    cin >> cases;
    for (int i = 1; i <= cases; i++){
        cin >> n;
        int aux = 0;
        for (int j = 1; j <= n; j++){
            if  (j == 1)
                cout << 9;
            if (j == 2)
                cout << 8;
            if (j == 3)
                cout << 9;
            if (j > 3){
                cout << aux;
                aux++;
                if (aux > 9){
                    aux = 0;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}