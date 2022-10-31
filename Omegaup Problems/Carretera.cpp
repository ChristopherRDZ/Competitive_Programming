/// Problem Link: https://omegaup.com/arena/problem/carretera 
/// Binary Search

#include <bits/stdc++.h>
using namespace std;

int pos[100002];
int vel[100002];
int n;

double distancia(double segundo){
    double mini = 1000000, maxi = -1000000;

    for (int i = 1; i <= n; i++){
        double pos_actual = pos[i];
        double aux = segundo * vel[i];

        pos_actual += aux;

        if (pos_actual < mini) mini = pos_actual;
        if (pos_actual > maxi) maxi = pos_actual;
    }
    double res = abs(mini - maxi);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> pos[i] >> vel[i];
    }

    double ini = 0, fin = 1000, mit;
    double respuesta = 1000000;
    while(ini <= fin){
        mit = (ini + fin) / 2;

        double aux1 = respuesta = distancia(mit);
        double aux2 = distancia(mit - 0.00001);

        if (aux1 > aux2) fin = mit - 0.00001;
        if (aux1 < aux2) ini = mit + 0.00001;
        if (aux1 == aux2) break;
    }

    respuesta = min(distancia(0), respuesta);

    cout << fixed << setprecision(7) << respuesta;

  return 0;
}