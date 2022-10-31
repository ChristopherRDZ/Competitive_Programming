#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];
int numeros[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, res = 0;
        cin >> n;
        for (int i = 1; i <= n; i++){
            int aux;
            cin >> aux;
            numeros[i] = aux;
            nums[aux]++;
        }
        int pos_aux = 1;
        for (int i = 1; i <= n; i++){
            if (nums[i] > 1){
                while(nums[i] > 1){
                    nums[numeros[pos_aux]]--;
                    pos_aux++;
                    res++;
                }
            }
        }
        for (int i = 1; i <= n; i++) nums[i] = 0;
        cout << res;
        cout << "\n";
    }

    return 0;
}