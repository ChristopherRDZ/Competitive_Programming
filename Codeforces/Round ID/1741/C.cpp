#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[2005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> nums[i];

        int res = n;
        for (int i = 1; i <= n; i++){
            int posibles = n - i;
            int sum = 0;
            for (int j = 1; j <= i; j++){
                sum += nums[j];
            }
            int l = 1, r = i;


            int ini = 1, sum_aux = 0;
            bool iguales = false;
            bool pudo = true;
            int maximo = i;
            int cuantos = 0;
            while(ini <= n){
                if(l <= ini && ini <= r){
                    if(sum_aux != 0 && sum_aux != sum){
                        pudo = false;
                        iguales = false;
                        break;
                    }
                    ini++;
                    continue;
                }
                sum_aux += nums[ini];
                cuantos++;
                if (sum_aux == sum){
                    sum_aux = 0;
                    iguales = true;
                    maximo = max(maximo, cuantos);
                    cuantos = 0;
                }
                if(sum_aux > sum){
                    pudo = false;
                    iguales = false;
                    break;
                }
                ini++;
            }
            if(sum_aux > 0 && sum_aux != sum){
                pudo = false;
                iguales = false;
            }
            if(pudo && iguales){
                res = min(res, maximo);
            }

            int a = 1, b = i + 1;
            for (int j = 1; j <= posibles; j++){
                sum -= nums[a];
                sum += nums[b];
                a++;
                r = b;
                b++;
                l = a;

                ini = 1;
                pudo = true;
                iguales = false;
                sum_aux = 0;
                maximo = i;
                while(ini <= n){
                    if(l <= ini && ini <= r){
                        if(sum_aux != 0 && sum_aux != sum){
                            pudo = false;
                            iguales = false;
                            break;
                        }
                        ini++;
                        continue;
                    }
                    sum_aux += nums[ini];
                    cuantos++;
                    if (sum_aux == sum){
                        sum_aux = 0;
                        iguales = true;
                        maximo = max(maximo, cuantos);
                        cuantos = 0;
                    }
                    if(sum_aux > sum){
                        pudo = false;
                        iguales = false;
                        break;
                    }
                    ini++;
                }
                if(sum_aux > 0){
                    pudo = false;
                    iguales = false;
                }
                if(pudo && iguales){
                    res = min(res, maximo);
                }
            }
        }
        cout << res;
        cout << "\n";
    }

    return 0;
}