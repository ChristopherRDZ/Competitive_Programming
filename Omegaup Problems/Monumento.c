/// Problem Link: https://omegaup.com/arena/problem/Monumento

#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);

  int aux_1 = 0; 
  int aux_2 = 1;
  int fibo = 0;

  for(int i=1; i<=n; i++){
    fibo = (aux_1 + aux_2) % 1000000;
    aux_1 = aux_2;
    aux_2 = fibo;
  } 
  printf("%d", fibo);
  return 0;
}