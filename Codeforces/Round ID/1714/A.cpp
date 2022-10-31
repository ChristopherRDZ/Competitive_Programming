#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, h, m;
        cin >> n >> h >> m;

        int res_a = INT_MAX;
        int res_b = INT_MAX;
        for (int i = 1; i <= n; i++){
            int a, b, aux_h = 0, aux_m = 0;
            int x = h, y = m;
            cin >> a >> b;
            if (a == h && b == m){
                res_a = 0;
                res_b = 0;
            }else{
                if(a < h){
                    aux_m = (60 - y);
                    y = 0;
                    x++;
                    aux_h = (24 - x);
                    x = 0;
                    while(x < a){
                        aux_h++;
                        x++;
                        if(x == 24) x = 0;
                    }
                    aux_m = aux_m + (b - y);
                }else{
                    if (a == h){
                        if (b < m){
                            aux_h = 23;
                            aux_m = (60 - y);
                            y = 0;
                            aux_m = aux_m + (b - y);
                        }
                        if (b > m){
                            aux_h = 0;
                            aux_m = (b - y);
                        }
                    }else{
                        while(x < a){
                            aux_h++;
                            x++;
                        }
                        if(b > y){
                            aux_m = (b - y);
                        }
                        if (b < y){
                            aux_h--;
                            aux_m = (60 - y);
                            y = 0;
                            aux_m = aux_m + (b - y);
                        }
                    }
                }
            }
            if (aux_m >= 60){
                aux_m = aux_m - 60;
                aux_h++;
            }
            if (aux_h < res_a){
                res_a = aux_h;
                res_b = aux_m;
            }else{
                if (aux_h == res_a){
                    if (aux_m < res_b){
                        res_b = aux_m;
                    }
                }
            }

        }
        cout << res_a << " " << res_b;

        cout << "\n";
    }

    return 0;
}