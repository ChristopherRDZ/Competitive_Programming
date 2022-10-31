/// Problem Link: https://omegaup.com/arena/problem/LIS
/// Segment Tree 

#include <iostream>
#include <map>
using namespace std;
#define NEUTRO 0
#define MAXN 1000005;

int nums[1048580];
int ST[2097160];
map <int, int > remap;

int f(int a, int b){
    return max(a, b);
}

int query(int nodo, int ini, int fin, int l, int r){
    if (l <= ini and fin <= r){
        return ST[nodo];
    }else{
        if (fin < l or r < ini){
            return NEUTRO;
        }else{
            int mitad = (ini + fin) / 2;
            int izq = query(nodo * 2, ini, mitad, l, r);
            int der = query(nodo * 2 + 1, mitad + 1, fin, l ,r);
            return f(izq, der);
        }
    }
}

void update(int nodo, int ini, int fin, int pos, int val){
    if (ini == pos and fin == pos){
        ST[nodo] = val;
    }else{
        if (fin < pos or pos < ini){
            return;
        }else{
            int mitad = (ini + fin) / 2;
            update(nodo * 2, ini, mitad, pos, val);
            update(nodo * 2 + 1, mitad + 1, fin, pos, val);
            ST[nodo] = f(ST[nodo * 2], ST[nodo * 2 + 1]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, r;
    int aux = 1, x;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x;
        remap[x] = i;
    }
    for (pair <int, int> b : remap){
        nums[b.second] = aux;
        aux++;
    }
    for (int i = n; i >= 1; i--){
        aux = query(1, 1, n, nums[i], n);
        aux += 1;
        update(1, 1, n, nums[i], aux);
    }
    cout << ST[1];
    return 0;
}