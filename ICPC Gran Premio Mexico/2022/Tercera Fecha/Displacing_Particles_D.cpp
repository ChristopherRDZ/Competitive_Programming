#include <bits/stdc++.h>
using namespace std;

int nums[1 << 20];
queue <int> actuales;
vector <int> lista;
int cuantos;

void calcula(int tiempo, int suma, int multiplica){
    while(!actuales.empty() && cuantos > 0){
        int x = actuales.front();
        actuales.pop();
        cuantos--;

        int valor1 = (x + suma) / 2;
        int valor2 = x / 2;
        actuales.push(valor1);
        actuales.push(valor2);
        nums[valor1] = tiempo;
        nums[valor2] = tiempo;
    }
    cuantos = 1 << multiplica;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    int pot_max = 1 << n;
    nums[pot_max / 2] = 0;

    int aux_n = n - 1, tiempo = 1;

    actuales.push(pot_max / 2);
    int multiplica = 1;
    cuantos = 1;
    while(aux_n > 0){
        calcula(tiempo, pot_max, multiplica);
        aux_n--;
        multiplica++;
        tiempo++;
    }
    cout << nums[x];
    cout << "\n";

    return 0;
}