#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];
int disponibles[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++){
            cin >> nums[i];
        }

        long long int tot = 0;
        for (int i = 1; i <= 31; i++){
            bool pudo = false;

            int ind;
            long long int aux, maximo = 0;
            for (int j = 1; j <= n; j++){
                if(!disponibles[j]){
                    aux = tot | nums[j];
                    if(aux > maximo){
                        maximo = aux;
                        ind = j;
                        pudo = true;
                    }
                }
            }

            if(pudo){
                cout << nums[ind] << " ";
                disponibles[ind] = true;
                tot = maximo;
            }else{
                break;
            }
        }

        for (int i = 1; i <= n; i++){
            if(!disponibles[i]) cout << nums[i] << " ";
            disponibles[i] = false;
        }
        cout << "\n";
    }
    return 0;
}