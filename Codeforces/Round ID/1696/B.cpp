#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, tot = 0, pos = n + 1;
        cin >> n;
        bool encuentra = false;
        for(int i = 1; i <= n; i++){
            cin >> nums[i];
            if (nums[i] > 0 && !encuentra){
                encuentra = true;
                pos = i;
            }
        }
        int fin = n;
        for (int i = n; i >= 1; i--){
            if (nums[i] != 0){
                break;
            }
            fin--;
        }
        int cont = 0;
        int cant = 0;
        int cant_fin = 0;
        for (int i = pos; i <= fin; i++){
            if (nums[i] == 0){
                cont++;
                if (cant > 0){
                    cant_fin++;
                    cant = 0;
                }
            }else{
                cant++;
            }
        }
        if (cant > 0) cant_fin++;
        cont++;

        if (cont <= cant_fin) tot = cont;
        else tot = cant_fin;

        tot = min (2, tot);

        cout << tot;
        cout << "\n";
    }
    return 0;
}