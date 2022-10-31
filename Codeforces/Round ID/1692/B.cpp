#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int num[100002];
int cubeta[100002];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        unordered_map<int,int> cub;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> num[i];
            cub[num[i]]++;
        }
        int tot = n;
        bool lleva = false;
        for (auto x: cub){
            if (x.second == 1) continue;
            if (x.second > 1){
                int aux = x.second - 1;
                if (lleva) aux++;
                if (aux % 2 == 0){
                    int res = aux / 2;
                    tot = tot - (res * 2);
                    lleva = false;
                }else{
                    int res = aux / 2;
                    lleva = true;
                    tot = tot - (res * 2);
                }
            }
        }
        if (lleva) tot -= 2;
        cub.clear();
        cout << tot;
        cout << "\n";
    }
    return 0;
}