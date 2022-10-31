/// Problem Link: https://omegaup.com/arena/problem/Maquina-de-Refrescos/
/// Sorting and prefix sum


#include <iostream>
#include <algorithm>
using namespace std;

struct rangos{
  int indice;
  int valor;
};

bool operator <(const rangos&a, const rangos&b){
  if (a.indice < b.indice) return true;
  if (a.indice == b.indice){
    if (a.valor < b.valor) return true;
  }
  return false;
}

rangos alumnos[100002];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, pos_aux = 1;
  cin >> n;
  for (int i = 1; i <= n; i++){
    ///inicia
    cin >> alumnos[pos_aux].indice;
    alumnos[pos_aux].valor = 1;
    pos_aux++;

    ///acaba
    cin >> alumnos[pos_aux].indice;
    alumnos[pos_aux].indice++;
    alumnos[pos_aux].valor = -1;
    pos_aux++;
  }

  sort(alumnos + 1, alumnos + pos_aux);

  int tot = 0, maximo = 0;
  for (int i = 1; i < pos_aux; i++){
    tot += alumnos[i].valor;
    if (tot > maximo) maximo = tot; 
  }

  cout << maximo;
  return 0;
}