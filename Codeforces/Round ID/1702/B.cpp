#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[205];
int cubeta[205];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, m, tot = 0;
        string s;

        cin >> s;

        int aux = 0;
        for (int i = 0; i < s.size(); i++){
            if (cubeta[s[i] - 'a' + 1] == 0){
                aux++;
                if (aux > 3){
                    tot++;
                    aux = 1;
                    for (int j = 1; j <= 30; j++) cubeta[j] = 0;
                }
                cubeta[s[i] - 'a' + 1]++;
            }
        }
        if (aux > 0) tot++;

        for (int j = 1; j <= 30; j++) cubeta[j] = 0;

        cout << tot;
        cout << "\n";
    }
    return 0;
}