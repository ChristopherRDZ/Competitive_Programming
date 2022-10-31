#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

char arre[100002];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, k, p_d = 0, p_i = 0;
        bool hay = false;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> arre[i];
        for (int i = 1; i <= n; i++){
            if (arre[i] == '1'){
                p_d = i;
                hay = true;
                break;
            }
        }
        if (!hay){
            cout << 0;
        }else{
            for (int i = n; i >= 1; i--){
                if (arre[i] == '1'){
                    p_i = i;
                    break;
                }
            }
            int cuan_i = n - p_i;
            int cuan_d = p_d - 1;
            if (p_d == p_i){
                if (k >= cuan_i){
                    arre[p_i] = '0';
                    arre[n] = '1';
                }else{
                    if (k >= cuan_d){
                        arre[p_d] = '0';
                        arre[1] = '1';
                    }
                }
            }else{
                if (k >= cuan_i){
                    arre[p_i] = '0';
                    arre[n] = '1';
                    k -= cuan_i;
                }
                if (k >= cuan_d){
                    arre[p_d] = '0';
                    arre[1] = '1';
                }
            }
            int tot = 0;
            for (int i = 1; i < n; i++){
                int aux = 0;
                aux = aux * 10 + (arre[i] - '0');
                aux = aux * 10 + (arre[i + 1] - '0');
                tot += aux;
            }
            cout << tot;
        }
        cout << "\n";
    }
    return 0;
}