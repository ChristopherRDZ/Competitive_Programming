#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        string a, b;
        cin >> a >> b;
        if(a == b) cout << "=";
        else{
            int numx_a = 0, numx_b = 0;
            char aux_a, aux_b;
            for (int i = 0; i < a.size(); i++){
                if(a[i] == 'X')
                    numx_a++;
                else
                    aux_a = a[i];

            }
            for (int i = 0; i < b.size(); i++){
                if(b[i] == 'X')
                    numx_b++;
                else
                    aux_b = b[i];
            }

            if(aux_a == aux_b){
                if(aux_a == 'S'){
                    if(numx_a > numx_b) cout << "<";
                    else cout << ">";
                }else{
                    if(numx_a > numx_b) cout << ">";
                    else cout << "<";
                }
            }else{
                if(aux_a == 'S' && aux_b == 'M') cout << "<";
                if(aux_a == 'S' && aux_b == 'L') cout << "<";
                if(aux_a == 'M' && aux_b == 'L') cout << "<";
                if(aux_a == 'M' && aux_b == 'S') cout << ">";
                if(aux_a == 'L' && aux_b == 'M') cout << ">";
                if(aux_a == 'L' && aux_b == 'S') cout << ">";
            }

        }
        cout << "\n";
    }

    return 0;
}