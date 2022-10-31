#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int cubeta[30];
int cubeta_aux[30];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int p;
        string s;

        //cin.ignore();
        cin >> s;
        cin >> p;

        int precio = 0;
        for (int i = 0; i < s.size(); i++){
            int pos = s[i] - 'a' + 1;
            precio += pos;
            cubeta[pos]++;
            cubeta_aux[pos]++;
        }

        if (precio <= p){
            cout << s;
        }else{
            for (int i = 26; i >= 1; i--){
                if (cubeta[i] > 0){
                    while(cubeta[i] > 0){
                        precio -= i;
                        cubeta[i]--;
                        if (precio <= p) break;
                    }
                }
                if (precio <= p) break;
            }
            for (int i = 0; i < s.size(); i++){
                int pos = s[i] - 'a' + 1;
                if (cubeta_aux[pos] > cubeta[pos]){
                    cubeta_aux[pos]--;
                }else{
                    cout << s[i];
                }
            }
        }

        for (int i = 0; i <= 28; i++){
            cubeta[i] = 0;
            cubeta_aux[i] = 0;
        }

        cout << "\n";

    }
    return 0;
}