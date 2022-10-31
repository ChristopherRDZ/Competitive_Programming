#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];
queue <int> ceros;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        long long int n, tot = 0, aux, x;
        string s;
        cin >> n;

        bool prim = false;
        for (int i = 1; i <= n; i++){
            cin >> nums[i];
            if (nums[i] > 0) prim = true;
            if (nums[i] == 0 && prim) ceros.push(i);
        }

        for(int i = 1; i <= n; i++){
            aux = nums[i];
            if (ceros.size() > 0){
                while(aux > 0){
                    int aux2 = ceros.front();
                    aux--;
                    ceros.pop();
                    nums[aux2]++;
                    tot++;
                    if (ceros.empty()) break;
                }
                nums[i] = aux;
            }
        }

        while(!ceros.empty()){
            ceros.pop();
        }

        for (int i = 1; i < n; i++){
            tot += nums[i];
        }
        cout << tot;
        cout << "\n";
    }
    return 0;
}