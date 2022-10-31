#include <iostream>
#include <vector>
using namespace std;

char b[100002];
int a[100002];
int c[100002];

int main(){
  int t, n;
  cin >> t;
  for (int i = 1; i <= t; i++){
    cin >> n;
    for (int j = 1; j <= n; j++){
      cin >> b[j];
    }
    for (int j = 1; j <= n; j++){
      if (j == 1){
        a[j] = 1;
        if (b[j] == '1') c[j] = 2;
        if (b[j] == '0') c[j] = 1;
      }else{
        if (b[j] == '1' and c[j - 1] == 1){
          a[j] = 1;
          c[j] = 2;
        }
        if (b[j] == '1' and c[j - 1] == 2){
          a[j] = 0;
          c[j] = 1;
        }
        if (b[j] == '1' and c[j - 1] == 0){
          a[j] = 1;
          c[j] = 2;
        }

        if (b[j] == '0' and c[j - 1] == 1){
          a[j] = 0;
          c[j] = 0;
        }
        if (b[j] == '0' and c[j - 1] == 2){
          a[j] = 1;
          c[j] = 1;
        }
        if (b[j] == '0' and c[j - 1] == 0){
          a[j] = 1;
          c[j] = 1;
        }
      }
    }
    for (int j = 1; j <= n; j++){
      cout << a[j];
    }
    cout << "\n";
  }
  return 0;
}