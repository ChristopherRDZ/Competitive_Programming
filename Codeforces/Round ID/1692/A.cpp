#include <bits/stdc++.h>
using namespace std;
 
#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;
 
int num[100002];
int cubeta[100002];
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
 
    while(t--){
        int a, b, c, d;
        string x;
        cin >> a >> b >> c >> d;
        int tot = 0;
        if (b > a) tot++;
        if (c > a) tot++;
        if (d > a) tot++;
        cout << tot;
        cout << "\n";
    }
    return 0;
}