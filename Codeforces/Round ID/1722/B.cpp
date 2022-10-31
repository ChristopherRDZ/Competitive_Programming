#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

char row1[105];
char row2[105];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> row1[i];
            if(row1[i] == 'G') row1[i] = 'B';
        }
        for(int i = 1; i <= n; i++){
            cin >> row2[i];
            if(row2[i] == 'G') row2[i] = 'B';
        }
        bool iguales = true;
        for(int i = 1; i <= n; i++){
            if(row1[i] != row2[i]) iguales = false;
        }
        if(iguales) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }

    return 0;
}