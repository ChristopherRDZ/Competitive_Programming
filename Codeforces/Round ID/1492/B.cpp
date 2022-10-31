#include <bits/stdc++.h>
#include <vector>
#include <map>
         
using namespace std;
             
/*bool operator<(const ura&a, const ura&b){
return a.dano_tot < b.dano_tot;
}*/           

struct c{
  int valor;
  int pos;
};

bool visited[100002];
map <int, int> card;
c cartas[100002];
int original[100002];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    card.clear();
    int n;
    int aux;
    cin >> n;
    for (int i = 1; i <= n; i++){
      visited[i] = false;
      cin >> aux;
      card[aux] = i;
      original[i] = aux;
    }
    int j = 1;
    for (pair <int, int> a: card){
      cartas[j].valor = a.first;
      cartas[j].pos = a.second;
      j++;
    }
    for (int i = j - 1; i >= 1; i--){
      for (int a = cartas[i].pos; a <= n; a++){
        if (visited[a]){
          break;
        }
        visited[a] = true;
        cout << original[a] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}