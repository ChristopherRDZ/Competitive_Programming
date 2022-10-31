/// Problem Link: https://omegaup.com/arena/problem/Matriz-Binaria/

#include <bits/stdc++.h>
using namespace std;

int matrix[52][52];

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> matrix[i][j];

  ///Change rows first
  for (int i = 1; i <= n; i++){
    if(matrix[i][1] == 0){ /// It's the best to change the row
      for (int j = 1; j <= m; j++){
        if(matrix[i][j] == 1)
          matrix[i][j] = 0;
        else
          matrix[i][j] = 1;
      }
    }
  }

  // Now change columns
  // If a column has fewer 0's than (n/2) , it's better to change values
  int change = n / 2;
  for (int i = 2; i <= m; i++){
    int cont = 0;
    for (int j = 1; j <= n; j++){
      if(matrix[j][i] == 1) 
        cont++;
    }
    if(cont <= change){
      for (int j = 1; j <= n; j++){
        if(matrix[j][i] == 1) 
          matrix[j][i] = 0;
        else
          matrix[j][i] = 1;
      }
    }
  }

  long long int tot = 0;
  /// Just make the sum 
  for (int i = 1; i <= n; i++){
    long long int pot = 0, aux;
    for (int j = m; j >= 1; j--){
      if(matrix[i][j] == 1){
        aux = (long long int)(1) << pot;
        tot += aux;
      }
      pot++;
    }
  }

  cout << tot;

  return 0;
}