#include <iostream>
using namespace std;
 
int nums[200005];
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i++){
            int aux;
            cin >> aux;
            nums[aux]++;
        }
        bool pudo = false;
        int resp = 0;
        for(int i = 1; i <= n; i++){
            if (nums[i] >= 3){
                pudo = true;
                resp = i;
            }
            nums[i] = 0;
        }
        if (!pudo) cout << -1;
        else cout << resp; 
        cout << "\n";
    }
    return 0;
}