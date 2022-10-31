#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    int tot;

    int x, y;
    if (n % 4 == 0){
        x = n / 4;
        y = n / 4;
    }else{
        int aux = n % 4;
        if (aux >= 2){
            x = n / 4;
            y = n / 4 + 1;
        }else{
            x = n / 4;
            y = n / 4;
        }
    }
    tot = x * y;
    cout << tot << "\n";
    return 0;

}