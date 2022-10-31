#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
typedef long long int ll;

int p[505];
int memo[40005][505];

bool palindromo(int n){
    queue <int> x;
    stack <int> y;
    int a = n;
    while(n > 0){
        int aux = n % 10;
        x.push(aux);
        n /= 10;
    }
    while(a > 0){
        int aux = a % 10;
        y.push(aux);
        a /= 10;
    }
    bool pudo = true;
    while(!x.empty()){
        int aux = x.front();
        int aux_2 = y.top();
        if (aux != aux_2){
            pudo = false;
            break;
        }
        x.pop();
        y.pop();
    }

    return pudo;
}

int dp(int i, int j){

    if (i == 0)
        return 1;

    if (p[j] > i || j > 498 || i < 0)
        return 0;

    if (memo[i][j] == -1)
        memo[i][j] = (dp(i - p[j], j) + dp(i, j + 1)) % 1000000007;

    return memo[i][j];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    int tot = 0;

    for (int i = 0; i <= 40000; i++){
        if (palindromo(i) && i >= 1)
            p[++tot] = i;
    }

    for (int i = 1; i <= 40000; i++)
        for (int j = 1; j <= 500; j++)
            memo[i][j] = -1;


    while(t--){
        int n;
        cin >> n;
        cout << dp(n, 1) << "\n";
    }
    return 0;
}