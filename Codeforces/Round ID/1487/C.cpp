    #include <bits/stdc++.h>
    #include <vector>
    #include <queue>
     
    using namespace std;
     
    /*bool operator<(const ura&a, const ura&b){
      return a.dano_tot < b.dano_tot;
    }*/
     
    int cubeta[105];
    int cubeta_aux[105];
     
    int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      int t;
      cin >> t;
      while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= 100; i++){
          cubeta[i] = 0;
          cubeta_aux[i] = 0;
        }
        if (n % 2 == 1){
          int mitad = (n / 2) + 1;
          int ganar = n - mitad;
          for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
              if (cubeta[i] < ganar){
                cubeta[i]++;
                cout << "1 ";
              }else{
                cubeta[j]++;
                cout << "-1 ";
              }
            }
          }
        }else{
          int empates = n / 2;
          int mitad = (n / 2) + 1;
          int ganar = n - mitad;
          for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
              if (cubeta[i] < ganar){
                cubeta[i]++;
                cout << "1 ";
              }else{
                if (cubeta_aux[i] == 0 and cubeta_aux[j] == 0){
                  cout << "0 ";
                  cubeta_aux[i]++;
                  cubeta_aux[j]++;
                }else{
                  cout << "-1 ";
                  cubeta[j]++;
                }
              }
            }
          }
        }
        cout << "\n";
      }
      return 0;
    }