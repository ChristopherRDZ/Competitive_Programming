#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;
     
vector <int> nums;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, k;
    int aux = 0;
    nums.clear();
    cin >> n >> k;
    for (int i = k + 1; i <= n; i++){
      nums.push_back(i);
      aux++;
    }
    for (int i = 1; i < k; i++){
      bool puede = true;
      for (int j = i + 1; j < k; j++){
        if (i + j == k){
          puede = false;
          break;
        }
      }
      if (puede){
        aux++;
        nums.push_back(i);
      }
    }
    cout << aux << "\n";
    for (int x: nums){
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}