#include <bits/stdc++.h>
using namespace std;

int nums[100002];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  int uno = 0, cero = 0;
  for (int i = 1; i <= n; i++){
    cin >> nums[i];
    if (nums[i] == 1){
      uno++;
    }else{
      cero++;
    }
  }
  int aux, pos;
  for (int i = 1; i <= q; i++){
    cin >> aux >> pos;
    if (aux == 2){
      if (pos <= uno){
        cout << 1 << "\n";
      }else{
        cout << 0 << "\n";
      }
    }else{
      if (nums[pos] == 1){
        nums[pos] = 0;
        uno--;
        cero++;
      }else{
        nums[pos] = 1;
        uno++;
        cero--;
      }
    }
  }
  return 0;
}