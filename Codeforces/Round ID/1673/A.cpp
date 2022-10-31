#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--){

        string s;
        cin >> s;

        ll tot_a = 0, tot_b = 0;
        if (s.size() % 2 == 0){
            cout << "Alice ";
            for (int i = 0; i < s.size(); i++)
                tot_a += (s[i] - 'a' + 1);
            cout << tot_a << "\n";
        }else{
            if (s.size() == 1){
                cout << "Bob ";
                tot_b = s[0] - 'a' + 1;
                cout << tot_b << "\n";
            }else{

                ll maxi = 0;
                bool xd = true;

                for (int i = 0; i < s.size() - 1; i++)
                    maxi += (s[i] - 'a' + 1);

                for (int i = 1; i < s.size(); i++)
                    tot_a += (s[i] - 'a' + 1);

                if (maxi > tot_a){
                    xd = false;
                    tot_a = maxi;
                }

                if (xd){
                    tot_b = s[0] - 'a' + 1;
                }else{
                    tot_b = s[s.size() - 1] - 'a' + 1;
                }

                //cout << tot_a << " " << tot_b << " xd\n";
                if (tot_a > tot_b){
                    cout << "Alice " << abs(tot_a - tot_b) << "\n";
                }else{
                    cout << "Bob " << abs(tot_a - tot_b) << "\n";
                }
            }
        }
    }
    return 0;
}