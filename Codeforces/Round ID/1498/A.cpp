#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int gcd(long long int a, long long int b){
  while (a!=0 and b!=0){
    if (a > b){
        a = a % b;
    }else{
        b = b % a;
      }
    }
    if (a == 0){
        return b;
    }else{
        return a;
    }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    long long int n;
    cin >> n;
    long long int suma = 0;
    long long int aux = n;
    while(aux > 0){
      suma += aux % 10;
      aux = aux / 10;
    }
    while (gcd(n, suma) <= 1){
      n++;
      aux = n;
      suma = 0;
      while(aux > 0){
        suma += aux % 10;
        aux = aux / 10;
      }
    }
    cout << n;
    cout << "\n";
  }
  return 0;
}