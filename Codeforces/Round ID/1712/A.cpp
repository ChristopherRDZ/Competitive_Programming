#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];
vector <int> falta;
int donde[100002];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            cin >> nums[i];
            donde[i] = 0;
        }

        int act = 0;
        for(int i = 1; i <= k; i++){
            donde[nums[i]] = i;
        }
        for (int i = 1; i <= k; i++){
            if(donde[i] == 0) act++;
        }
        cout << act;
        cout << "\n";
    }

    return 0;
}