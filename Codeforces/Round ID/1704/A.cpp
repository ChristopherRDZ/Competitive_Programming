#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[100005];
int cub_a[3];
int cub_b[3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        string a, b;

        cin >> n >> m;
        cin >> a >> b;

        cub_a[0] = 0;
        cub_a[1] = 0;
        cub_b[0] = 0;
        cub_b[1] = 0;
        for (int i = 0; i < n; i++) cub_a[a[i] - '0']++;
        for (int i = 0; i < m; i++) cub_b[b[i] - '0']++;

        if (cub_a[0] >= cub_b[0] && cub_a[1] >= cub_b[1]){
            int pos_a = n - 1, pos_b = m - 1, aux = 0;
            while(a[pos_a] == b[pos_b]){
                pos_a--;
                pos_b--;
                aux++;
                if (aux == m) break;
            }
            if (aux == m || m == 1){
                cout << "YES";
            }else{
                bool encontro = false;
                int posicion = 0;
                for (int i = 0; i <= pos_a; i++){
                    if (a[i] == b[0]){
                        int xd = 0;
                        for (int j = i; j <= pos_a; j++){
                            if (a[j] == b[xd]){
                                xd++;
                                if(xd > pos_b){
                                    encontro = true;
                                    posicion = j + 1;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (encontro){
                    if (pos_b == 0){
                        cout << "YES";
                    }else{
                        bool pudo = true;
                        while(posicion <= pos_a){
                            if (a[posicion] != b[pos_b]){
                                pudo = false;
                                break;
                            }
                        }
                        if (pudo) cout << "YES";
                        else cout << "NO";
                    }
                }else{
                    cout << "NO";
                }
            }
        }else{
            cout << "NO";
        }
        cout << "\n";
    }

    return 0;
}