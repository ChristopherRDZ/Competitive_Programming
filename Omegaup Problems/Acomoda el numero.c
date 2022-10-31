/// Problem Link: https://omegaup.com/arena/problem/AcomodandoOMI
/// "Sorting" problem

#include <stdio.h>
using namespace std;

int main() {
  int n, primero, cont = 0, aux;
  scanf("%d %d", &n, &primero);
  for (int i = 1; i < n; i++){
    scanf("%d", &aux);
    if (aux < primero) cont++;
  }
  printf("%d", cont);
  return 0;
}