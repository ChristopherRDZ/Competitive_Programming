#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int num[200005];
int cub[15];


bool encuentra(int n, int sum, int origen)
{
    bool res = false;
    unordered_set<int> s;
    bool prim = false;
    for (int i = 1; i <= n; i++)
    {
        if (origen == num[i] && !prim){
            prim = true;
            continue;
        }
        int temp = sum - num[i];
        if (s.find(temp) != s.end()){
            res = true;
            break;
        }
        s.insert(num[i]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> num[i];
            num[i] = num[i] % 10;
            cub[num[i]]++;
        }
        unordered_set <int> objetivo;
        unordered_set <int> objetivo_2;
        unordered_set <int> objetivo_3;
        for (int i = 1; i <= n; i++){
            objetivo.insert(13 - num[i]);
            objetivo_2.insert(3 - num[i]);
            objetivo_3.insert(23 - num[i]);
        }
        bool f = false;
        for (auto x: objetivo){
            bool pudo = encuentra(n, x, 13 - x);
            if (pudo){
                f = true;
                break;
            }
        }

        for (auto x: objetivo_2){
            bool pudo = encuentra(n, x, 3 - x);
            if (pudo){
                f = true;
                break;
            }
        }

        for (auto x: objetivo_3){
            bool pudo = encuentra(n, x, 23 - x);
            if (pudo){
                f = true;
                break;
            }
        }

        if (f) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}