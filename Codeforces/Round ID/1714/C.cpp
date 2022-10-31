#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

stack <int> nums;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int dispo = 9;
        int act = 0;
        while(x >= 1){
            if (x > (9 - act)){
                nums.push(dispo);
                x = x - dispo;
                dispo--;
                act++;
            }else{
                nums.push(x);
                x = 0;
            }
        }
        while(!nums.empty()){
            int aux = nums.top();
            cout << aux;
            nums.pop();
        }
        cout << "\n";
    }


    return 0;
}