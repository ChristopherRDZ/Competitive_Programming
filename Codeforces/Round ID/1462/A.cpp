#include <bits/stdc++.h>
using namespace std;

int final[302];
int arreglo[302];

int main(){
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++){
        bool l = true;
        cin >> n;
        int left = 1, rigth = n;
        for (int j = 1; j <= n; j++){
            cin >> arreglo[j];
        }
        for (int j = 1; j <= n; j++){
            if (l){
                final[j] = arreglo[left];
                left++;
                l = false;
            }else{
                final[j] = arreglo[rigth];
                rigth--;
                l = true;
            }
        }
        for (int j = 1; j <= n; j++){
            cout << final[j] << " ";
        }
            cout <<"\n";
    }
   return 0; 
}