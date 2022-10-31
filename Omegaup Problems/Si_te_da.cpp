/// Problem Link: https://omegaup.com/arena/problem/siteda

#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, f;
  cin >> a >> b;
  cout << a << " " << b << " ";
  f = (a + b) % 10;
  cout << f << " ";
  c = b; // anterior - > 8
  d = f; // actual -> 9
  int cont = 1;
  while (a != c || b != d){
    f = (c + d) % 10;
    cout << f << " ";
    c = d;
    d = f;
    cont++;
  }
  cout << "\n" << cont;
  return 0; 
}