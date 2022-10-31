#include <bits/stdc++.h>
using namespace std;

vector <int> alturas[1000005];
int globlos[500010];
bool dead[500010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> aux;
        globlos[i] = aux;
        alturas[aux].push_back(i);
    }
    int tot = 0, i_aux = 0;
    vector <int>::iterator it;
    for (int i = 1; i <= n; i++){
        if(!dead[i]){
            bool puede = true;
            int alt = globlos[i];
            int posi = 0;
            tot++;
            dead[i] = true;
            i_aux = i;
            it = alturas[alt].begin();
            alturas[alt].erase(it);
            while(puede){
                if(alturas[alt - 1].size() >= 1){
                    puede = false;
                    int ini = 0, fin = alturas[alt - 1].size() - 1, mit;
                    while(ini <= fin){
                        mit = (ini + fin) / 2;
                        if(alturas[alt - 1][mit] > i_aux){
                            puede = true;
                            posi = alturas[alt - 1][mit];
                            it = alturas[alt - 1].begin() + mit;
                            fin = mit - 1;
                        }
                        if(alturas[alt - 1][mit] < i_aux){
                            ini = mit + 1;
                        }
                    }

                    if(puede){
                        dead[posi] = true;
                        alturas[alt - 1].erase(it);
                        alt--;
                        i_aux = posi;
                    }else{
                        break;
                    }
                }else{
                    puede = false;
                    break;
                }
            }
        }
    }
    cout << tot;
    cout << "\n";

    return 0;
}