/// Problem Link:  https://omegaup.com/arena/problem/jarras
/// graphs - bfs (Interactive problem)

#include "jarras.h"
#include <bits/stdc++.h>

using namespace std;

struct p{
    int jar_1;
    int jar_2;
};

int visited[1002][1002];
p padre[1002][1002];
int opcion[1002][1002];
int distancia[1002][1002];
int respuestas[100002];
int dis, aux, ind;
int o1_j1, o2_j1, o3_j1, o4_j1, o5_j1, o6_j1;
int o1_j2, o2_j2, o3_j2, o4_j2, o5_j2, o6_j2;
queue <int> jarra_1;
queue <int> jarra_2;

int bfs(int obj, int n1, int n2){
    while (!jarra_1.empty()){
        int x1, x2;
        x1 = jarra_1.front();
        x2 = jarra_2.front();
        jarra_1.pop();
        jarra_2.pop();
        if (x1 == obj){
            int aux1, aux2, a1, a2;
            aux1 = x1;
            aux2 = x2;
            a1 = x1;
            a2 = x2;
            while (aux1 != 0 or aux2 != 0){
                respuestas[ind] = opcion[a1][a2];
                ind++;
                aux1 = padre[a1][a2].jar_1;
                aux2 = padre[a1][a2].jar_2;
                a1 = aux1;
                a2 = aux2;
            }
            dis = distancia[x1][x2];
            break;
        }else{
            if (visited[x1][x2] == 0){
                visited[x1][x2] = 1;
                /// llenar jarra 1 (opcion 1)
                o1_j1 = n1;
                o1_j2 = x2;
                if (visited[o1_j1][o1_j2] == 0 ){
                    distancia[o1_j1][o1_j2] = distancia[x1][x2] + 1;
                    jarra_1.push(o1_j1);
                    jarra_2.push(o1_j2);
                    padre[o1_j1][o1_j2].jar_1 = x1;
                    padre[o1_j1][o1_j2].jar_2 = x2;
                    opcion[o1_j1][o1_j2] = 1;
                }
                /// llenar jarra 2 (opcion 2)
                o2_j1 = x1;
                o2_j2 = n2;
                if (visited[o2_j1][o2_j2] == 0){
                    distancia[o2_j1][o2_j2] = distancia[x1][x2] + 1;
                    jarra_1.push(o2_j1);
                    jarra_2.push(o2_j2);
                    padre[o2_j1][o2_j2].jar_1 = x1;
                    padre[o2_j1][o2_j2].jar_2 = x2;
                    opcion[o2_j1][o2_j2] = 2;
                }
                /// tirar contenido jarra 1 (opcion 3)
                o3_j1 = 0;
                o3_j2 = x2;
                if (visited[o3_j1][o3_j2] == 0){
                    distancia[o3_j1][o3_j2] = distancia[x1][x2] + 1;
                    jarra_1.push(o3_j1);
                    jarra_2.push(o3_j2);
                    padre[o3_j1][o3_j2].jar_1 = x1;
                    padre[o3_j1][o3_j2].jar_2 = x2;
                    opcion[o3_j1][o3_j2] = 3;
                }
                /// tirar contenido jarra 2 (opcion 4)
                o4_j1 = x1;
                o4_j2 = 0;
                if (visited[o4_j1][o4_j2] == 0){
                    distancia[o4_j1][o4_j2] = distancia[x1][x2] + 1;
                    jarra_1.push(o4_j1);
                    jarra_2.push(o4_j2);
                    padre[o4_j1][o4_j2].jar_1 = x1;
                    padre[o4_j1][o4_j2].jar_2 = x2;
                    opcion[o4_j1][o4_j2] = 4;
                }
                /// vaciar contenido jarra 1 a jarra 2 (opcion 5)
                if (x2 >= n2){
                    o5_j1 = x1;
                    o5_j2 = x2;
                }else{
                    aux = x1 + x2;
                    if (aux > n2){
                        o5_j2 = n2;
                        o5_j1 = x1 - (n2 - x2);
                    }
                    if (aux <= n2){
                        o5_j1 = 0;
                        o5_j2 = aux;
                    }
                }
                if (visited[o5_j1][o5_j2] == 0){
                    distancia[o5_j1][o5_j2] = distancia[x1][x2] + 1;
                    jarra_1.push(o5_j1);
                    jarra_2.push(o5_j2);
                    padre[o5_j1][o5_j2].jar_1 = x1;
                    padre[o5_j1][o5_j2].jar_2 = x2;
                    opcion[o5_j1][o5_j2] = 5;
                }
                /// vaciar contenido jarra 2 a jarra 1 (opcion 6)
                if (x1 >= n1){
                    o6_j1 = x1;
                    o6_j2 = x2;
                }else{
                    aux = x1 + x2;
                    if (aux > n1){
                        o6_j2 = x2 - (n1 - x1);
                        o6_j1 = n1;
                    }
                    if (aux <= n1){
                        o6_j1 = aux;
                        o6_j2 = 0;
                    }
                }
                if (visited[o6_j1][o6_j2] == 0){
                    distancia[o6_j1][o6_j2] = distancia[x1][x2] + 1;
                    jarra_1.push(o6_j1);
                    jarra_2.push(o6_j2);
                    padre[o6_j1][o6_j2].jar_1 = x1;
                    padre[o6_j1][o6_j2].jar_2 = x2;
                    opcion[o6_j1][o6_j2] = 6;
                }
            }
        }
    }
    return dis;
}
// Main
//	void verterAgua(int fuente, int destino)



void programa(int objetivo, int capacidadJarra1, int capacidadJarra2) {
    int tot;
    distancia[0][0] = 0;
    padre[0][0].jar_1 = 0;
    padre[0][0].jar_2 = 0;
    opcion[0][0] = 0;
    jarra_1.push(0);
    jarra_2.push(0);
    tot = bfs(objetivo, capacidadJarra1, capacidadJarra2);
    tot--;
    for (int i = tot ; i >= 0; i--){
        if (respuestas[i] == 1)
            verterAgua(0,1);
        if (respuestas[i] == 2)
            verterAgua(0,2);
        if (respuestas[i] == 3)
            verterAgua(1,3);
        if (respuestas[i] == 4)
            verterAgua(2,3);
        if (respuestas[i] == 5)
            verterAgua(1,2);
        if (respuestas[i] == 6)
            verterAgua(2,1);
    }
	// FIXME
}