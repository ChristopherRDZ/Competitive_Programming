#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];
int necesita[200005];
ll imp[200005];
ll ult[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, m, tot = 0;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> nums[i];
        }
        int aux1 = 0, aux2 = 0;
        for(int i = 2; i < n; i++){
            if (i % 2 == 0){

            }
            int dif = max(nums[i - 1], nums[i + 1]);
            if (nums[i] > dif) necesita[i] = 0;
            else necesita[i] = dif - nums[i] + 1;
        }

        ll res = 0, op1 = 0, op2 = 0;
        if (n % 2 == 1){
            for (int i = 2; i < n ; i += 2){
                res += necesita[i];
            }
        }else{
            int pos_aux = 0;
            for (int i = 2; i < n; i += 2) op1 += necesita[i];
            for (int i = 3; i < n; i += 2){
                op2 += necesita[i];
                ++pos_aux;
            }
            ll acum = 0;
            int pos_aux2 = pos_aux;
            for(int i = n - 1; i >= 3; i -= 2){
                acum += necesita[i];
                imp[pos_aux--] = acum;
            }

            acum = 0;
            int a = 0, b = 0;
            for (int i = 2; i < n; i += 2){
                ult[++a] = acum + imp[++b];
                acum += necesita[i];
            }
            ult[++a] = acum;

            ll mini = ult[1];
            for(int i = 1; i <= a; i++){
                if (ult[i] < mini) mini = ult[i];
            }
            res = mini;
        }

        cout << res;

        cout << "\n";
    }
    return 0;
}