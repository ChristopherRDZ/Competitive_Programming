#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  if (n % m == 0){
    cout << n / m;
  }else{
    cout << n / m + 1;
  }
  cout << "\n";


  return 0;
}