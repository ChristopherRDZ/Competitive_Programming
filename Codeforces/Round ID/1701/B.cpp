#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];
bool visited[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << 2 << "\n";
        int act = 1, aux = 3;
        for (int i = 1; i <= n; i++){
            if (act <= n){
                cout << act << " ";
                act *= 2;
            }else{
                act = aux;
                cout << act << " ";
                act *= 2;
                aux += 2;
            }
        }
        cout << "\n";
    }
    return 0;
}