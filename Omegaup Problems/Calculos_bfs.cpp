/// Problem Link: https://omegaup.com/arena/problem/OIEG2013SSA/
/// Breadth-First-Search (OMI - 1998)

#include <bits/stdc++.h>

using namespace std;

int visited[10002];


int distancia[10002];

int dis, a, b, n, m, d;

queue <int> cola;

int bfs (int i){

    while (!cola.empty()){

        int numero = cola.front();

        cola.pop();

        if (numero == n){

            dis = distancia[numero];

            break;

        }else{

            if (visited[numero] == 0){

                m = numero * a;

                if (m > 9999){

                    m = 1;

                }


                distancia[m] = distancia[numero]+1;

                d = numero / b;

                cola.push(m);

                if (d != 0){

                    cola.push(d);

                }


                distancia[d] = distancia[numero]+1;

                visited[numero] = 1;

            }

        }

    }

    return dis;

}

int main()

{

    cin >> a >> b >> n;

    cola.push(1);



    distancia[1] = 0;

    cout << bfs(1);

    return 0;

}