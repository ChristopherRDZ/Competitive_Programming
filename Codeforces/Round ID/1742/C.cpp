#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

char tablero[15][15];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        for (int i = 1; i <= 8; i++){
            for (int j = 1; j <= 8; j++){
                cin >> tablero[i][j];
            }
        }

        int tot = 0;
        char res;
        for (int i = 1; i <= 8; i++){
            tot = 0;
            for (int j = 1; j <= 8; j++){
                if(tablero[i][j] == 'R') tot++;
            }
            if(tot == 8){
                res = 'R';
                break;
            }
        }

        for (int i = 1; i <= 8; i++){
            tot = 0;
            for (int j = 1; j <= 8; j++){
                if(tablero[j][i] == 'B') tot++;
            }
            if(tot == 8){
                res = 'B';
                break;
            }
        }
        cout << res;

        cout << "\n";
    }

    return 0;
}