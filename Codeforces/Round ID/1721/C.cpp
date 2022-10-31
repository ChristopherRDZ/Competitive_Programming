#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int a[200005];
int b[200005];
int m[200005];
int res[200005];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        int pos_aux = 1;
        for(int i = 1; i <= n; i++){
            if(a[i] <= b[pos_aux]){
                cout << b[pos_aux] - a[i] << " ";
                m[i] = pos_aux;
            }else{
                while(b[pos_aux] < a[i])
                    pos_aux++;
                m[i] = pos_aux;
                cout << b[pos_aux] - a[i] << " ";
            }
        }
        cout << "\n";

        int max_pos = n;
        for(int i = n; i >= 1; i--){
            if(m[i] == i){
                res[i] = b[max_pos] - a[i];
                max_pos = m[i] - 1;
            }else{
                res[i] = b[max_pos] - a[i];
            }
        }
        for(int i = 1; i <= n; i++) cout << res[i] << " ";
        cout << "\n";


    }

    return 0;
}