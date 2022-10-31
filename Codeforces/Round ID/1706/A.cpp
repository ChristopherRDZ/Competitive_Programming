#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];
bool visit[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n, m, tot = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            cin >> nums[i];
        }
        for (int i = 1; i <= n; i++){
            int aux = (m + 1) - nums[i];
            if (nums[i] < aux){
                if (visit[nums[i]]) visit[aux] = true;
                else visit[nums[i]] = true;
            }else{
                if (visit[aux]) visit[nums[i]] = true;
                else visit[aux] = true;
            }
        }
        for (int i = 1; i <= m; i++){
            if (visit[i]) cout << "A";
            else cout << "B";
            visit[i] = false;
        }

        cout << "\n";
    }
    return 0;
}