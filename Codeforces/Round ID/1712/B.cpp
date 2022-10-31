#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[100005];
int cubeta[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n % 2 == 1){
            cout << 1 << " ";
            int tot = n - 1;
            tot = n / 2;
            int a = 3;
            int b = 2;
            for(int i = 1; i <= tot; i++){
                cout << a << " " << b << " ";
                a += 2;
                b += 2;
            }
        }else{
            int a = 2;
            int b = 1;
            int tot = n / 2;
            for(int i = 1; i <= tot; i++){
                cout << a << " " << b << " ";
                a += 2;
                b += 2;
            }
        }
        cout << "\n";
    }

    return 0;
}