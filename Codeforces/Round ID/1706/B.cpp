#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

vector <int> pos[200005];
int cubeta[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, m, tot = 0;
        cin >> n;
        for (int i = 1; i <= n; i++){
            int aux;
            cin >> aux;
            pos[aux].push_back(i);
        }
        for (int i = 1; i <= n; i++){
            if (pos[i].size() > 0){
                int anterior = pos[i][0];
                int acum = 1;
                for (int j = 1; j < pos[i].size(); j++){
                    int aux = pos[i][j];
                    if ((aux - 1) == anterior){
                        acum++;
                        anterior = aux;
                    }else{
                        int dist = aux - anterior - 1;
                        if (dist % 2 == 0){
                            acum++;
                            anterior = aux;
                        }
                    }
                }
                cubeta[i] = acum;
            }
        }
        for (int i = 1; i <= n; i++){
            cout << cubeta[i] << " ";
            cubeta[i] = 0;
            pos[i].clear();
        }

        cout << "\n";
    }
    return 0;
}