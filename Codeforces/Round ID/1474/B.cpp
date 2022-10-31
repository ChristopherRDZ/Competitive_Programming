#include <iostream>
#include <vector>
using namespace std;

vector <int> nums;
bool vis[200050];
typedef long long int lld;

void calculate(){
  for (lld i = 2; i <= 200010; ++i) {
    if (vis[i]) continue;
    nums.push_back(i);
    for (lld j = i * i; j <= 200010; j += i) {
      vis[j] = true;
    }
  }
}

int main(){
  calculate();
  int t, d, aux, tam;
  cin >> t;
  for (int i = 1; i <= t; i++){
    cin >> d;
    lld a, b;
    for (int j = 0; j < nums.size(); j++){
      if (nums[j] > d){
        a = nums[j];
        aux = j;
        break;
      }
    }
    for (int j = aux; j < nums.size(); j++){
      if ((nums[j] - a) >= d){
        b = nums[j];
        break;
      }
    }
    lld res = b * a;
    cout << res << "\n";
  }
  return 0;
}