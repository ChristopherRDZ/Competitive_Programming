#include <bits/stdc++.h>
using namespace std;

int cubeta[1005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, aux, tot = 0;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> aux;
            aux = abs(aux);
            cubeta[aux]++;
        }
        if (cubeta[0] > 0) tot++;
        cubeta[0] = 0;
        for (int i = 1; i <= 1000; i++){
            if (cubeta[i] > 1){
                tot += 2;
            }
            if (cubeta[i] == 1) tot++;
            cubeta[i] = 0;
        }
        cout << tot << "\n";
    }
    return 0;
}