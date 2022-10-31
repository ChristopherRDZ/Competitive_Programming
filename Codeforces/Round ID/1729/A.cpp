#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int arre[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;

        int op1 = a - 1, op2;

        if(b > c){
            op2 = b - 1;
        }else{
            op2 = c - b;
            op2 = op2 + (c - 1);
        }
        if(op1 == op2) cout << "3";
        if(op1 < op2) cout << "1";
        if(op1 > op2) cout << "2";
        cout << "\n";
    }
    return 0;
}