///Problem Link: https://omegaup.com/arena/problem/Lectura-Veloz

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, l, d;
  int s[1005];
  int t[1005];
  int r[1005];

  cin>>N>>K;

  for (int i=1; i<=K; i++){
    cin>>s[i];
    cin>>t[i];
    cin>>r[i];
  }
  for (int i = 1; i <= K; i++){
    l=s[i]*t[i];
    int cum = 0;
    int n2 = N; /// 10
    while (l < n2){ /// 10
      cum += t[i];
      cum += r[i];
      n2 = n2 - l; /// 10 -> 2 
    }
    if (l >= n2){
      if (n2 % s[i] == 0){
        cum += (n2 / s[i]);
      }else{
        cum += (n2 / s[i]) + 1;
      }
    }
    cout << cum << "\n";
  }
  return 0;
}