#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int num[102];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        long long int tot = 0;

        string s = "Mike";
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> num[i];

        if (n == 1){
            cout << s;
        }else{
            if (n % 2 == 1){
                cout << s;
            }else{
                bool joe = true;
                int mini = INT_MAX, pos;
                for (int i = 1; i <= n; i++){
                    if (num[i] < mini){
                        mini = num[i];
                        pos = i;
                    }
                }
                if (pos % 2 == 0) cout << s;
                else cout << "Joe";
            }
        }

        cout << "\n";
    }
    return 0;
}