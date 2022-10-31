/// Problem Link: https://omegaup.com/arena/problem/iOI-2009-Garage
/// IOI_2009

// IOI_2009

#include <iostream>

#include <queue>

using namespace std;

         

int espacio[102];

int carros[2002];

int cubeta[102];

queue<int> cola;

         

int main(){

    ios_base::sync_with_stdio(0);

    int n, m, aux;

    int tot = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; i++){

        cin >> espacio[i];

    }

    for (int i = 1; i <= m; i++){

        cin >> carros[i];

    }

    int lugar = 1;

    for (int i = 1; i <= m * 2; i++){

        cin >> aux;

        if (aux > 0){

            lugar = 0;

            for (int j = 1; j <= n; j++){

                if (cubeta[j] == 0){

                    cubeta[j] = aux;

                    lugar = j;

                    break;

                }

              }

                if (lugar != 0){

                    tot += espacio[lugar] * carros[aux];

                }else{

                    cola.push(aux);

                }

        }else{

            for (int j = 1; j <= n; j++){

                if (cubeta[j] == abs(aux)){

                    cubeta[j] = 0;

                    lugar = j;

                }

            }

            if (cola.size() >= 1){

                int f = cola.front();

                cola.pop();

                tot += espacio[lugar] * carros[f];

                cubeta[lugar] = f;

              }

        }

    }

    cout << tot;

    return 0;

}