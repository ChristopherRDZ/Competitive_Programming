#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];
int potencias[200005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        for (int i = 1;  i <= n; i++){
            cin >> nums[i];
            potencias[i] = 0;
        }

        int pot_tot = 0;
        for (int i = 1; i <= n; i++){
            int aux = nums[i];
            while(aux > 0 && aux % 2 == 0){
                pot_tot++;
                aux = aux / 2;
            }
            aux = i;
            while(aux > 0 && aux % 2 == 0){
                potencias[i]++;
                aux = aux / 2;
            }
        }

        sort(potencias + 1, potencias + n + 1);

        if(pot_tot >= n){
            cout << 0;
        }else{
            int n_aux = n;
            int acum = 0;
            bool entro = false;
            for (int i = n; i >= 1; i--){
                if(potencias[i] > 0){
                    pot_tot += potencias[i];
                    acum++;
                }
                if(pot_tot >= n) break;
            }

            if(pot_tot >= n) cout << acum;
            else cout << -1;
        }

        cout << "\n";
    }

    return 0;
}