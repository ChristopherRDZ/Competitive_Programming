        #include <bits/stdc++.h>
        #include <vector>
         
        using namespace std;
             
        /*bool operator<(const ura&a, const ura&b){
        return a.dano_tot < b.dano_tot;
        }*/
             
        int grafo[1002][1002];
         
        int main(){
          ios_base::sync_with_stdio(0); cin.tie(0);
          int t;
          cin >> t;
          while(t--){
            int n, m;
            cin >> n >> m;
            char letra;
            int impar;
            for (int i = 1; i <= n; i++){
              for (int j = 1; j <= n; j++){
                cin >> letra;
                if (letra == 'a') grafo[i][j] = 1;
                if (letra == 'b') grafo[i][j] = 2;
              }
            }
            // si es par, siempre se puede
            if (m % 2 == 1){
              cout << "YES\n";
              cout << "1 ";
              for (int i = 1; i <= m; i++){
                if (i % 2 == 0){
                  cout << "1 ";
                }else{
                  cout << "2 ";
                }
              }
            }else{
              bool igual = false;
              int pos_i, pos_j;
              for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                  if (i != j){
                    if (grafo[i][j] == grafo[j][i]){
                      pos_i = i;
                      pos_j = j;
                      igual = true;
                      break;
                    }
                  }
                }
                if (igual){
                  break;
                }
              }
              if (igual){
                cout << "YES\n";
                cout << pos_i << " ";
                for (int i = 1; i <= m; i++){
                  if (i % 2 == 0){
                    cout << pos_i << " "; 
                  }else{
                    cout << pos_j << " ";
                  }
                }
              }else{
                int x, y, z;
                for (int i = 1; i <= n; i++){
                  for (int j = 1; j <= n; j++){
                    if (i != j){
                      if (grafo[i][j] != grafo[j][i]){
                        for (int a = 1; a <= n; a++){
                          if (a != i and a != j){
                            if (grafo[j][a] == grafo[i][j]){
                              if (grafo[j][a] != grafo[a][j]){
                                x = i;
                                y = j;
                                z = a;
                                igual = true;
                                break;
                              }
                            }
                          }
                        }
                      }
                    }
                    if (igual){
                      break;
                    }
                  }
                  if (igual){
                    break;
                  }
                }
                if (igual){
                  cout << "YES\n";
                  int aux = m / 2;
                  if (aux % 2 == 0){
                    cout << y << " ";
                    for (int i = 1; i <= m / 2; i++){
                      if (i % 2 == 0){
                        cout << y << " ";
                      }else{
                        cout << x << " ";
                      }
                    }
                    for (int i = m / 2 + 1; i <= m; i++){
                      if (i % 2 == 0){
                        cout << y << " ";
                      }else{
                        cout << z << " ";
                      }
                    }
                  }else{
                    cout << x << " ";
                    for (int i = 1; i <= m / 2; i++){
                      if (i % 2 == 0){
                        cout << x << " ";
                      }else{
                        cout << y << " ";
                      }
                    }
                    for (int i = m / 2 + 1; i <= m; i++){
                      if (i % 2 == 0){
                        cout << z << " ";
                      }else{
                        cout << y << " ";
                      }
                    }
                  }
                }else{
                  cout << "NO";
                }
              } 
            }
            for (int i = 1; i <= n; i++){
              for (int j = 1; j <= n; j++){
                grafo[i][j] = 0;
              }
            }
            cout << "\n";
          }
          return 0;
        }