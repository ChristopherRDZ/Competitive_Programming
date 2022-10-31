#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];
int toca[1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> nums[i];
        }
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++){
            char letra = s[i];
            if(toca[nums[i]] == 0){
                toca[nums[i]] = letra;
            }
        }
        string aux = "";
        for (int i = 0; i < n; i++){
            aux += toca[nums[i]];
        }
        for (int i = 0; i < n; i++){
            toca[nums[i]] = 0;
        }
        if(aux == s) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}