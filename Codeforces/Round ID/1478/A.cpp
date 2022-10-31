#include <iostream>
#include <vector>
using namespace std;

typedef long long int lld;
lld nums[100002];
int mult[15];

int main(){
  lld t, n, d;
  ///string n
  cin >> t;
  for (int i = 1; i <= t; i++){
    cin >> n;
    for (int j = 1; j <= n; j++){
      cin >> nums[j];
    }
    int aux = 1;
    int maxi = 1;
    for (int j = 1; j < n; j++){
      if (nums[j] == nums[j + 1]){
        aux++;
      }else{
        if (aux > maxi){
          maxi = aux;
        }
        aux = 1;
      }
    }
    if (aux > maxi){
      maxi = aux;
    }
    cout << maxi << "\n";
  }
  return 0;
}