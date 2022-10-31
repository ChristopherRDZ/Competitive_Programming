#include <bits/stdc++.h>
using namespace std;

map <int, int> nuevo_id;
vector <int> pidieron[200005];
vector <int> tienen[200005];
map <int, int> respuesta;


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, m, act = 1, aux;
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    int id, x;
    cin >> id >> x;
    nuevo_id[id] = act;
    for (int i = 1; i <= x; i++){
      cin >> aux;
      pidieron[act].push_back(aux);
    }
    act++;
  }

  for (int i = 1; i <= m; i++){
    int id, x;
    cin >> id >> x;
    if (nuevo_id[id] == 0) nuevo_id[id] = act;
    for (int i = 1; i <= x; i++){
      cin >> aux;
      tienen[nuevo_id[id]].push_back(aux);
    }
    act++;
  }

  int not_requested = 0, missed = 0, alum = 0;
  for (auto valor: nuevo_id){
    int ult_x, pudo = 0;
    respuesta.clear();
    for (int v: pidieron[valor.second])
      respuesta[v]++;
    for (int v: tienen[valor.second])
      respuesta[v]--;

    for (auto v: respuesta){
      if (v.second == -1 || v.second == 1){
        ult_x = v.first;
        pudo = 1;
      }
    }

    if(pudo == 1){
      alum++;
      cout << valor.first << " ";
        for (auto v: respuesta){
          if (v.second == -1){
            cout << "-" << v.first;
            not_requested++;
          }
          if (v.second == 1){
            cout << "+" << v.first;
            missed++;
          }
          if(v.first != ult_x) cout << " ";
      }
    }
    cout << "\n";
  }
  if(alum > 0)
    cout << "MISTAKES IN " << alum << " STUDENTS: " <<not_requested << " NOT REQUESTED, " << missed << " MISSED";
  else
    cout << "GREAT WORK! NO MISTAKES FOUND!";

  cout << "\n";

  return 0;
}