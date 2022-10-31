#include <bits/stdc++.h>
#include <map>
using namespace std;
     
int matriz[102][102];
int s[5];
     
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, arriba, der, abajo, izq;
    int tot_arr, tot_lados;
    cin >> n >> arriba >> der >> abajo >> izq;
    tot_arr = arriba + abajo;
    tot_lados = der + izq;
    bool posible = true;
    if (tot_arr >= (n * 2 - 1)){
      if (der == 0 or izq <= 0){
        posible = false;
      }else{
        if (der == 1 and izq <= 1){
          posible = false;
        }else{
          if (der <= 1 and izq == 1){
            posible == false;
          }else{
            if (tot_arr == n * 2){
              if (der <= 1 or izq <= 1){
                posible = false;
              }
            }
          }
        }
      }
    }
    if (tot_lados >= (n * 2 - 1)){
      if (arriba == 0 or abajo <= 0){
        posible = false;
      }else{
        if (arriba == 1 and abajo <= 1){
          posible = false;
        }else{
          if (arriba <= 1 and abajo == 1){
            posible == false;
          }else{
            if (tot_lados == n * 2){
              if (arriba <= 1 or abajo <= 1){
                posible = false;
              }
            }
          }
        }
      }
    }
    if (arriba == n){
      if (der == 0 or izq == 0){
        posible = false;
      }
    }
    if (abajo == n){
      if (der == 0 or izq == 0){
        posible = false;
      }
    }
    if (der == n){
      if (arriba == 0 or abajo == 0){
        posible = false;
      }
    }
    if (izq == n){
      if (arriba == 0 or abajo == 0){
        posible = false;
      }
    }
    if (arriba == n - 1){
      if (der <= 0 and izq <= 0){
        posible = false;
      }
    }
    if (abajo == n - 1){
      if (der <= 0 and izq <= 0){
        posible = false;
      }
    }
    if (izq == n - 1){
      if (arriba <= 0 and abajo <= 0){
        posible = false;
      }
    }
    if (der == n - 1){
      if (arriba <= 0 and abajo <= 0){
        posible = false;
      }
    }
      if (arriba == n - 1 and abajo == n - 1){
        if (izq <= 1 and der == 0){
          posible = false;
        }else{
          if (izq == 0 and der <= 1){
            posible = false;
          }
        }
      }
      if (izq == n - 1 and der == n - 1){
        if (arriba <= 1 and abajo == 0){
          posible = false;
        }else{
          if (arriba == 0 and abajo <= 1){
            posible = false;
          }
        }
      }
    if (posible){
      cout << "YES";
    }else{
      cout << "NO";
    }
    cout << "\n";
  }
  return 0;
}