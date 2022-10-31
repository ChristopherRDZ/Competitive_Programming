#include <bits/stdc++.h>
using namespace std;

map <string, int> aparaciones;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c, pos = 0;
    cin >> n >> c;
    string aux = "";
    char x;
    for (int i = 1; i <= n; i++){
        aux = "";
        for (int j = 0; j < c; j++){
            cin >> x;
            aux += x;
            if(x == '*'){
                pos = j;
            }
        }
        for (int j = 'a'; j <= 'z'; j++){
            aux[pos] = j;
            aparaciones[aux]++;
        }
    }

    int maxi = 0;
    string respuesta;
    for (auto palabra: aparaciones){
        if(palabra.second > maxi){
            respuesta = palabra.first;
            maxi = palabra.second;
        }
    }
    cout << respuesta << " " << maxi;
    cout << "\n";

    return 0;
}