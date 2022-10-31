/// Problem Link: https://omegaup.com/arena/problem/OMI2018-CDMX-EDOMEX-4
/// Bucket

#include <stdio.h>
int cubeta[1000005];

int main() {

  int n, h, a;
  scanf("%d %d %d", &n, &h, &a);

  for (int i = 1; i <= a; i++){
    int x, y;
    scanf("%d %d", &x, &y);

    int aux = x + y + 1;
    if (aux > n) aux = n + 1;
    cubeta[aux]--;
    
    aux = x - y;
    if (aux <= 0) aux = 1;
    cubeta[aux]++;
  }
  
  for (int i = 1; i <= n; i++) cubeta[i] += cubeta[i - 1];

  int res = 0;
  for (int i = 1; i <= n; i++){
    if (cubeta[i] == 0){
      res++;
      int pos = i + (2 * h); 
      i = pos;
    }
  }
  printf("%d", res);
  return 0;
}