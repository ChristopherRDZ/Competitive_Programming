#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];
map <string, int> existe;
string pala[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, tot = 0, aux;
        string s;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> s;
            pala[i] = s;
            existe[s]++;
        }
        for (int i = 1; i <= n; i++){
            bool pudo = false;
            if (pala[i].size() == 1){
                cout << "0";
            }else{
                string aux = "", aux2 = "";
                for (int j = 0; j < pala[i].size(); j++){
                    aux += pala[i][j];
                    aux2 = "";
                    for (int k = j + 1; k < pala[i].size(); k++){
                        aux2 += pala[i][k];
                    }
                    if (existe[aux] > 0 && existe[aux2] > 0){
                        pudo = true;
                        break;
                    }
                }
                if (pudo) cout << "1";
                else cout << "0";
            }
        }

        existe.clear();

        cout << "\n";


    }
    return 0;
}