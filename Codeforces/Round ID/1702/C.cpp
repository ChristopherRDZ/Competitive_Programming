#include <iostream>
#include <map>
using namespace std;

map <int, int> primero;
map <int, int> ultimo;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, k, tot = 0, aux;
        string s;

        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            cin >> aux;

            if (primero[aux] == 0) primero[aux] = i;
            ultimo[aux] = i;
        }

        for (int i = 1; i <= k; i++){
            int a, b;
            cin >> a >> b;

            bool pudo = false;
            if (primero[a] < ultimo[b] && primero[a] != 0 && ultimo[b] != 0) pudo = true;
            
            if (pudo) cout << "YES";
            else cout << "NO";
            cout << "\n";
        }

        primero.clear();
        ultimo.clear();

    }
    return 0;
}