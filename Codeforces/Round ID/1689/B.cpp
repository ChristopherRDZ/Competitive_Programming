#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int num[1005];
int res[1005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> num[i];
        if (n == 1){
            cout << -1;
        }else{
            int toca = 1;
            if (n % 2 == 0){
                bool entro = false;
                while(true){
                  if (toca == num[toca]){
                    if (toca == n){
                        res[toca] = res[toca - 1];
                        res[toca - 1] = toca;
                        break;
                    }else{
                        res[toca] = toca + 1;
                        res[toca + 1] = toca;
                        toca += 2;
                    }
                  }else{
                      res[toca] = toca;
                      toca++;
                  }
                  if (toca > n) break;
                }
            }else{
                while(true){
                    if (toca == num[toca]){
                    res[toca] = toca + 1;
                    res[toca + 1] = toca;
                    toca += 2;
                  }else{
                      res[toca] = toca;
                      toca++;
                  }
                  if (toca >= n) break;
                }
                if (toca == num[toca]){
                    res[toca] = res[toca - 1];
                    res[toca - 1] = toca;
                }else{
                    res[toca] = toca;
                }
            }
            for (int i = 1; i <= n; i++) cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}