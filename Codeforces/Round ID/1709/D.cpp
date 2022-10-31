///Problema Codeforces: https://codeforces.com/contest/1709/problem/D
#include <iostream>
using namespace std;

#define MAXM 300005

int ST[MAXM * 2];
int blocked[MAXM];

int f(int a, int b){
    return max(a, b);
}

void crear_st(int nodo, int ini, int fin){
    if (ini == fin){
        ST[nodo] = blocked[ini];
    }else{
        int mitad = (ini + fin) / 2;
        crear_st(nodo * 2, ini, mitad);
        crear_st(nodo * 2 + 1, mitad + 1, fin);
        ST[nodo] = f(ST[nodo * 2], ST[nodo * 2 + 1]);
    }
}

int query(int nodo, int ini, int fin, int l, int r){
    if (l <= ini && fin <= r) return ST[nodo];
    if (fin < l || r < ini) return 0;

    int mitad = (ini + fin) / 2;
    int izq = query(nodo * 2, ini, mitad, l, r);
    int der = query(nodo * 2 + 1, mitad + 1, fin, l, r);
    return f(izq, der);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;

    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> blocked[i];
    crear_st(1, 1, m);

    cin >> q;
    for (int i = 1; i <= q; i++){
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;

        if (y1 > y2){
            int aux1 = y1, aux2 = x1;
            y1 = y2;
            x1 = x2;
            y2 = aux1;
            x2 = aux2;
        }

        int dis_y = abs(x1 - x2);
        int dis_x = abs(y1 - y2);
        if (dis_y % k == 0 && dis_x % k == 0){
            int ini = y1 + 1, fin = y2 - 1;
            if (ini > fin){
                cout << "YES";
            }else{
                int res = query(1, 1, m, ini, fin) + 1;
                int peq = min(x1, x2);
                if (res > peq){
                    int dis = abs(res - peq);
                    int dif = dis % k;
                    if (dif != 0) dif = k - dif;
                    if (dif + res <= n){
                        cout << "YES";
                    }else{
                        cout << "NO";
                    }
                }else{
                    cout << "YES";
                }
            }
        }else{
            cout << "NO";
        }
        cout << "\n";
    }

    return 0;
}