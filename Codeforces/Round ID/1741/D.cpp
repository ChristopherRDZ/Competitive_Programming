#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[300002];
vector <int> aux;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> nums[i];
        }

        bool pudo = true;
        int pot2 = -1;
        int aux_n = n;
        while(aux_n > 0){
            pot2++;
            aux_n = aux_n / 2;
        }

        int pasos = 0;
        for (int i = 1; i <= pot2; i++){
            int cuantos = 1 << i;
            for (int j = 1; j <= n; j++){
                int minimo1 = INT_MAX, minimo2 = INT_MAX;
                int fin  = j + (cuantos / 2) - 1;

                for (int k = j; k <= fin; k++){
                    minimo1 = min(minimo1, nums[k]);
                }

                int inicio = j + cuantos / 2;
                fin = j + cuantos - 1;
                for (int k = inicio; k <= fin; k++){
                    minimo2 = min(minimo2, nums[k]);
                }

                if(minimo2 < minimo1){
                    int pos_aux = j;
                    for (int k = inicio; k <= fin; k++){
                        aux.push_back(nums[k]);
                        nums[k] = nums[pos_aux++];
                    }

                    pos_aux = 0;
                    fin  = j + (cuantos / 2) - 1;
                    for (int k = j; k <= fin; k++){
                        nums[k] = aux[pos_aux++];
                    }
                    pasos++;
                    aux.clear();
                }
                j += cuantos - 1;
            }
        }
        pudo = true;
        for (int i = 1; i < n; i++){
            if(nums[i] > nums[i + 1]){
                pudo = false;
                break;
            }
        }
        if(pudo){
            cout << pasos;
        }else{
            cout << -1;
        }
        cout << "\n";
    }

    return 0;
}