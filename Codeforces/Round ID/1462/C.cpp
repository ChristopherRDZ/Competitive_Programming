#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, x;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> n;
        x = n;
        if (n >= 10 and n <= 17){
            x = n - 9;
            x = x * 10 + 9;
        }
        if (n >= 18 and n <= 24){
            x = n - 17;
            x = x * 100 + 89; 
        }
        if (n >= 25 and n <= 30){
            x = n - 24;
            x = x * 1000 + 789; 
        }
        if (n >= 31 and n <= 35){
            x = n - 30;
            x = x * 10000 + 6789; 
        }
        if (n >= 36 and n <= 39){
            x = n - 35;
            x = x * 100000 + 56789; 
        }
        if (n >= 40 and n <= 42){
            x = n - 39;
            x = x * 1000000 + 456789; 
        }
        if (n >= 43 and n <= 44){
            x = n - 42;
            x = x * 10000000 + 3456789; 
        }
        if (n == 45){
            x = 123456789;
        }
        if (n >= 46){
            x = -1;
        }
        cout << x << "\n";
    }
   return 0; 
}