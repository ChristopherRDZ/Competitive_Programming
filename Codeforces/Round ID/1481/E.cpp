#include <bits/stdc++.h>
#include <vector>
#include <map>
#define MAX 500002

using namespace std;

/*bool operator<(const ura&a, const ura&b){
return a.dano_tot < b.dano_tot;
}*/           

int libros[MAX];
int primera[MAX];
int ultimo[MAX];
int cubeta[MAX];
int memo[MAX];
int n;

int dp(int i){
  if (i > n){
    return 0;
  }else{
    if (memo[i] == -1){
      cubeta[libros[i]]++;
      int tomar = dp(i + 1);
      int no_tomar;
      if (primera[libros[i]] == i){
        no_tomar = cubeta[libros[i]] + dp(ultimo[libros[i]] + 1);
      }else{
        no_tomar = cubeta[libros[i]];
      }
      memo[i] = max(tomar, no_tomar);
    }
    return memo[i];
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> libros[i];
    if (primera[libros[i]] == 0){
      primera[libros[i]] = i;
    }
    ultimo[libros[i]] = i;
    memo[i] = -1;
  }
  for (int a = n; a >= 1; a--){
    dp(a);
  }
  cout << n - memo[1];
  return 0;
}