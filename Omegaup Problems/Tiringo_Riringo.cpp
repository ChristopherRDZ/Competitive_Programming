/// Problem Link: https://omegaup.com/arena/problem/probD
/// Binary Search

#include <bits/stdc++.h>
using namespace std;

struct ura{
  int pos;
  int val;
};

bool operator <(const ura&a, const ura&b){
  if (a.pos < b.pos) return true;
  return false;
}

ura cuerdas[200005];

struct ura2{
  int ini;
  int fin;
  int valor;
};

ura2 resp[100005];

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, q, aux = 1;
  cin >> n >> q;
  for (int i = 1; i <= n; i++){
    int a, b;
    cin >> a >> b;
    cuerdas[aux].pos = a;
    cuerdas[aux++].val = 1;
    cuerdas[aux].pos = b + 1;
    cuerdas[aux++].val = -1;
  }

  sort(cuerdas + 1, cuerdas + aux);
  int acum = 0, aux2 = 0;

  resp[0].ini = INT_MIN;
  for (int i = 1; i < aux; i++){
    acum += cuerdas[i].val;
    if(cuerdas[i].pos != cuerdas[i + 1].pos){
      resp[++aux2].ini = cuerdas[i].pos;
      resp[aux2].valor = acum;
      resp[aux2 - 1].fin = resp[aux2].ini - 1;
    }
  }
  resp[aux2].fin = INT_MAX;

  for (int i = 1; i <= q; i++){
    int x;
    cin >> x;

    int l = 0, r = aux2, mitad;
    while(l <= r){
      mitad = (l + r) / 2;

      if (resp[mitad].ini <= x && resp[mitad].fin >= x){
        cout << resp[mitad].valor << "\n";
        break;
      }
      if (resp[mitad].ini > x) r = mitad - 1;
      if (resp[mitad].fin < x) l = mitad + 1;
    }

  }
  return 0;
}