#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;

  int aux = n;
  int tot = 0;
  while(aux > 0){
    int dig = aux % 10;
    if (dig != 0 and n % dig == 0) tot++;
    aux = aux / 10;
  }
  cout << tot;
  return 0;
}