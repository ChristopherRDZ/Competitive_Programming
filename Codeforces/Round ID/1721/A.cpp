#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

int nums[200005];
int bucket[50];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        for (int i = 1; i <= 4; i++)
        {
            char aux;
            cin >> aux;
            bucket[aux - 'a' + 1]++;
        }

        int dife = 0;
        for(int i = 1; i <= 30; i++){
            if(bucket[i] > 0) dife++;
            bucket[i] = 0;
        }

        if(dife == 1) cout << "0";
        if(dife == 2) cout << "1";
        if(dife == 3) cout << "2";
        if(dife == 4) cout << "3";
        cout << "\n";
    }

    return 0;
}