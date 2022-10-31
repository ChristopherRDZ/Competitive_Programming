#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;


long long int arre[100005];
map <int, int> bucket;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        bucket.clear();
        int n, tot = 0;
        cin >> n;

        fr(n){
            cin >> arre[i];
            bucket[arre[i]]++;
        }

        if (n == 1){
            cout << -1 << "\n";
        }else{
            bool pudo = true;

            int tam = 0, auxi = 1;
            for (auto x: bucket){
                if (x.second == n) break;
                //cout << x.first << " " << x.second << "\n";
                if (x.second == 1){
                    pudo = false;
                    break;
                }
            }

            if (pudo){
                int ini = 1, fin = 0;
                for (int i = 1; i < n; i++){
                    if (arre[i] == arre[i + 1]){
                        fin = i + 1;
                    }else{
                        cout << fin << " " ;
                        for (int j = ini; j < fin; j++) cout << j << " ";
                        ini = i + 1;
                    }
                }
                cout << fin << " ";
                for (int i = ini; i < fin; i++) cout << i << " ";
                cout << "\n";
            }else{
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}