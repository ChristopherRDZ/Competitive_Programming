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
        int n;
        cin >> n;
        if (n == 1){
            cout << 1;
        }else{
            if (n % 2 == 0){
            int aux1 = 1, aux2 = 2;
                while(aux1 <= n && aux2 <= n){
                    cout << aux2 << " " << aux1 << " ";
                    aux2+=2;
                    aux1+=2;
                }
            }else{
                cout << "2 3 1 ";
                int aux1 = 4, aux2 = 5;
                while(aux1 <= n && aux2 <= n){
                    cout << aux2 << " " << aux1 << " ";
                    aux2+=2;
                    aux1+=2;
                }
            }
        }
        cout << "\n";
    }

    return 0;
}