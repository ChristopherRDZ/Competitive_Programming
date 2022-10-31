#include <bits/stdc++.h>
using namespace std;
 
#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;
 
struct pareja{
    int a;
    int b;
};
 
int nums[200005];
int indices[1005];
vector <int> diferentes;
vector <pareja> coprimos;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int t;
    cin >> t;
 
    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> nums[i];
            indices[nums[i]] = i;
        }
        for (int i = 1; i <= 1000; i++){
            if(indices[i] != 0)
                diferentes.push_back(i);
        }
        for (int i = 0; i < diferentes.size(); i++){
            for (int j = 0; j < diferentes.size(); j++){
                if(__gcd(diferentes[i], diferentes[j]) == 1){
                    coprimos.push_back({diferentes[i], diferentes[j]});
                }
            }
        }
 
        int sum_max = 0;
        for (auto x: coprimos){
            int sum = indices[x.a] + indices[x.b];
            if(sum > sum_max)
                sum_max = sum;
        }
        if(coprimos.size() == 0) sum_max = -1;
        cout << sum_max;
        cout << "\n";
 
        for (int i = 1; i <= 1000; i++) indices[i] = 0;
        diferentes.clear();
        coprimos.clear();
    }
 
    return 0;
}