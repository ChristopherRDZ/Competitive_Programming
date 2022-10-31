#include <bits/stdc++.h>
#include <map>
using namespace std;

struct ura{
    int num;
    int pos;
};

bool operator<(const ura&a, const ura&b){
    if (a.num < b.num){
        return true;
    }else{
        return false;
    }
}

ura numeros[200002];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, n, a, m = INT_MAX, r = 0;
    cin >> x;
    for (int i = 1; i <= x; i++){
        cin >> n;
        m = INT_MAX;
        r = 0;
        for (int j = 1; j <= n; j++){
            cin >> a;
            numeros[a].num ++;
            numeros[a].pos = j;
            if (a < m){
                m = a;
            }
            if (a > r){
                r = a;
            }
        }
        bool ban = false;
        for (int j = m; j <= r; j++){
            if (numeros[j].num == 1){
                if (ban == false){
                    cout << numeros[j].pos << "\n";
                }
                ban = true;
            }
            numeros[j].num = 0;
            numeros[j].pos = 0;
        }
        if (ban == false){
            cout << -1 << "\n";
        }
    }
    return 0;
}