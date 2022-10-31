#include <iostream>
#include <map>
using namespace std;

int trees[52];
map <double, int> bucket;

int main(){
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> n;
        for (int j = 1; j <= n; j++){
            cin >> trees[j];
        }
        int r = 0;
        double d;
        for (int j = 1; j <= n; j++){
            for (int a = j + 1; a <= n; a++){
                d = trees[a] - trees[j];
                d = d / 2;
                bucket[d]++;
                if (bucket[d] == 1){
                    r++;
                }
            }       
        }
        cout << r << "\n";
        bucket.clear();
    }
    return 0;
}