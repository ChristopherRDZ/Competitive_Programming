#include <iostream>
#include <map>
using namespace std;

int trees;
map <int, int> bucket;

int main(){
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> n;
        int r = 0;
        for (int j = 1; j <= n; j++){
            cin >> trees;
            bucket[trees]++;
            if (bucket[trees] > 1){
                bucket[trees + 1] ++;
            }
        }
        for (pair <int, int> x: bucket){
            r++;
        }
        cout << r << "\n";
        bucket.clear();
    }
    return 0;
}