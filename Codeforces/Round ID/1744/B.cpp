#include <bits/stdc++.h>
using namespace std;
 
#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;
 
ll nums[200005];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int t;
    cin >> t;
 
    while(t--){
        int n, q;
        cin >> n >> q;
 
        ll pares = 0, impares = 0, sum = 0, tot;
        for (int i = 1; i <= n; i++){
            cin >> nums[i];
            if(nums[i] % 2 == 0) pares++;
            else impares++;
 
            sum += nums[i];
        }
        ll p, aux;
        for (int i = 1; i <= q; i++){
            cin >> p >> aux;
            if(p == 0){
                tot = pares * aux;
                sum += tot;
                cout << sum << "\n";
 
                if(aux % 2 == 1){
                    impares += pares;
                    pares = 0;
                }
            }else{
                tot = impares * aux;
                sum += tot;
                cout << sum << "\n";
 
                if(aux % 2 == 1){
                    pares += impares;
                    impares = 0;
                }
            }
        }
    }
 
    return 0;
}