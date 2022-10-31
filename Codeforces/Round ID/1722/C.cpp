#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

map <string, int> bucket;
map <string, int> nino1;
map <string, int> nino2;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string aux;
        int res1 = 0, res2 = 0, res3 = 0;
        for(int i = 1; i <= n; i++){
            cin >> aux;
            nino1[aux]++;
            bucket[aux]++;
            res1 += 3;
        }
        for(int i = 1; i <= n; i++){
            cin >> aux;
            bucket[aux]++;
            nino2[aux]++;
            res2 += 3;
            if(bucket[aux] == 2){
                res1 -= 2;
                res2 -= 2;
            }
        }
        for(int i = 1; i <= n; i++){
            cin >> aux;
            bucket[aux]++;
            res3 += 3;
            if(bucket[aux] == 3){
                res1 -= 1;
                res2 -= 1;
                res3 -= 3;
            }
            if(bucket[aux] == 2){
                if(nino1[aux] > 0){
                    res1 -= 2;
                    res3 -= 2;
                }
                if(nino2[aux] > 0){
                    res2 -= 2;
                    res3 -= 2;
                }
            }
        }
        bucket.clear();
        nino1.clear();
        nino2.clear();
        cout << res1 << " " << res2 << " " << res3;
        cout << "\n";
    }

    return 0;
}