#include <iostream>
using namespace std;
 
int nums[100005];
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i++) cin >> nums[i];
        
        bool pudo = true;
        int aux = nums[1] % 2;
        int aux2;
        if (n > 1) aux2 = nums[2] % 2;
        
        for (int i = 1; i <= n; i++){
            if (i % 2 == 0 && nums[i] % 2 != aux2) pudo = false;
            if (i % 2 == 1 && nums[i] % 2 != aux) pudo = false;
        }
        if (pudo) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}