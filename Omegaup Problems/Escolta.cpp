/// Problem Link: https://omegaup.com/arena/problem/Escolta
/// Ac hoc?

#include <bits/stdc++.h>

using namespace std;

int grupo_1[100002];
int grupo_2[100002];
int grupo_3[100002];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;
    int aux1, aux2, aux3, mini, maxi;
    int i_1 = 1, i_2 = 1, i_3 = 1;
    int r1, r2, r3;
    int maximo = INT_MAX;
    int diferencia;
    cin >> a >> b >> c;
    for (int i=1;i<=a;i++){
        cin >> grupo_1[i];
    }
    for (int i=1;i<=b;i++){
        cin >> grupo_2[i];
    }
    for (int i=1;i<=c;i++){
        cin >> grupo_3[i];
    }
    sort (grupo_1+1, grupo_1+a+1);
    sort (grupo_2+1, grupo_2+b+1);
    sort (grupo_3+1, grupo_3+c+1);
    r1 = grupo_1[1];
    r2 = grupo_2[1];
    r3 = grupo_3[1];
    i_1 = 1;
    i_2 = 1;
    i_3 = 1;
    while (i_1<=a or i_2<=b or i_3<=c){
        aux1 = grupo_1[i_1];
        aux2 = grupo_2[i_2];
        aux3 = grupo_3[i_3];
        mini = min (aux1, aux2);
        mini = min (mini, aux3);
        maxi = max (aux1, aux2);
        maxi = max (maxi, aux3);
        diferencia = maxi - mini;
        if (diferencia < maximo){
            maximo = diferencia;
            r1 = aux1;
            r2 = aux2;
            r3 = aux3;
        }
        if (i_1 == a){
            if (i_2 == b){
                if (i_3 == c){
                    break;
                }
            }
        }
        if (mini == aux1){
            i_1++;
            if (i_1 > a){
                i_1 = a;
                mini = min (aux2, aux3);
                if (mini == aux2){
                    i_2++;
                    if (i_2 > b){
                        i_2 = b;
                        i_3++;
                        if (i_3 > c){
                            i_3 = c;
                        }
                    }
                }else{
                    i_3++;
                    if (i_3 > c){
                        i_3 = c;
                        i_2++;
                        if (i_2 > b){
                            i_2 = b;
                        }
                    }
                }
            }
        }else{
            if (mini == aux2){
                i_2++;
                if (i_2 > b){
                    i_2 = b;
                    mini = min (aux1, aux3);
                    if (mini == aux1){
                        i_1++;
                        if (i_1 > a){
                            i_1 = a;
                            i_3++;
                            if (i_3 > c){
                                i_3 = c;
                            }
                        }
                    }else{
                        i_3++;
                        if (i_3 > c){
                            i_3 = b;
                            i_1++;
                            if (i_1 > a){
                                i_1 = a;
                            }
                        }
                    }
                }
            }else{
                i_3++;
                if (i_3 > c){
                    i_3 = c;
                    mini = min (aux1, aux2);
                    if (mini == aux1){
                        i_1++;
                        if (i_1 > a){
                            i_1 = a;
                            i_2++;
                            if (i_2 > b){
                                i_2 = b;
                            }
                        }
                    }else{
                        i_2++;
                        if (i_2 > b){
                            i_2 = b;
                            i_1++;
                            if (i_1 > a){
                                i_1 = a;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << r1 << " " << r2 << " " << r3;
    return 0;
}