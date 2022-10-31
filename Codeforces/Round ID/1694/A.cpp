#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int num[200002];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int tot = 0;
        string s = "";
        int a, b;
        cin >> a >> b;

        if (a > b){
            int cuan = a / b;
            while(a > 0 || b > 0){
                if (b > 0){
                    s += '1';
                    b--;
                }
                int tam = min(cuan, a);
                for (int i = 1; i <= tam; i++) s += '0';

                a -= tam;
                if (a <= 0) break;
            }
        }else{
            int cuan = b / a;
            while(a > 0 || b > 0){
                if (a > 0){
                    s += '0';
                    a--;
                }
                int tam = min(cuan, b);
                for (int i = 1; i <= tam; i++) s += '1';
                b -= tam;
                if (b <= 0) break;
            }
        }
        cout << s;
        cout << "\n";
    }
    return 0;
}