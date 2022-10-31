#include <iostream>
using namespace std;

struct dato{
  long long int ini;
  long long int fin; 
};

dato f[1000005];
dato a[1000005];
int d[1000005];
int w[1000005];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) cin >> d[i];
  for (int i = 1; i <= n; i++) cin >> w[i];

  /// Hacia frente
  for (int i = 1; i <= n; i++){
    f[i].ini = f[i - 1].fin + d[i];
    f[i].fin = f[i].ini + w[i];
  }

  ///Hacia atras
  for (int i = n; i >= 1; i--){
    a[i].ini = a[i + 1].fin + d[i + 1];
    a[i].fin = a[i].ini + w[i];
  }

  long long int res = 0;
  for (int i = 1; i <= n; i++){
    if(f[i].fin < a[i].ini || a[i].fin < f[i].ini) continue;

    if(f[i].ini >= a[i].ini && f[i].fin >= a[i].fin)
      res = a[i].fin - f[i].ini;

    if(f[i].fin <= a[i].fin && a[i].ini >= f[i].ini)
      res = f[i].fin - a[i].ini;
  }

  cout << res << "\n";

  return 0;
}