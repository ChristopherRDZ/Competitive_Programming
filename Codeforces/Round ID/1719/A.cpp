#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[100005];
int cubeta[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(m % 2 == 0){
            if(n % 2 == 1){
                cout << "Burenka";
            }else{
                cout << "Tonya";
            }
        }else{
            if(n % 2 == 0){
                if(m % 2 == 1){
                    cout << "Burenka";
                }else{
                    cout << "Tonya";
                }
            }else{
                if(m % 2 == 1){
                    if(n % 2 == 0){
                        cout << "Burenka";
                    }else{
                        cout << "Tonya";
                    }
                }else{
                    if(n % 2 == 1){
                        if(m % 2 == 0){
                            cout << "Burenka";
                        }else{
                            cout << "Tonya";
                        }
                    }
                }
            }
        }
        cout << "\n";
    }

    return 0;
}