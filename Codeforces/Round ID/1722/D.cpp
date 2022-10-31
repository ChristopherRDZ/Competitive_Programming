#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

char miradas[200005];
queue <int> derecha;
queue <int> izquierda;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        ll tot_act = 0;
        for(int i = 1; i <= n; i++){
            cin >> miradas[i];
            if(miradas[i] == 'L') tot_act = tot_act + (i - 1);
            if(miradas[i] == 'R') tot_act = tot_act + (n - i);
        }

        int mitad = n / 2;
        for(int i = 1 ; i <= mitad; i++){
            if(miradas[i] == 'L') derecha.push(i);
        }

        mitad++;
        for(int i = n; i >= mitad; i--){
            if(miradas[i] == 'R') izquierda.push(i);
        }

        int k = 1;
        while(!derecha.empty() || !izquierda.empty()){
            if(derecha.empty()){
                if(izquierda.empty()) break;

                ll aux_izq = izquierda.front();
                aux_izq = aux_izq - 1;
                miradas[izquierda.front()] = 'L';
                tot_act += aux_izq;
                tot_act = tot_act - (n - izquierda.front());
                izquierda.pop();
                cout << tot_act << " ";
                k++;
            }
            if(izquierda.empty()){
                if(derecha.empty()) break;

                ll aux_der = derecha.front();
                aux_der = n - aux_der;
                miradas[derecha.front()] = 'R';
                tot_act += aux_der;
                tot_act = tot_act - (derecha.front() - 1);
                derecha.pop();
                cout << tot_act << " ";
                k++;
            }
            if(!izquierda.empty() && !derecha.empty()){
                ll aux_der = derecha.front();
                ll aux_izq = izquierda.front();
                aux_der = n - aux_der;
                aux_izq = aux_izq - 1;
                if(aux_der >= aux_izq){
                    miradas[derecha.front()] = 'R';
                    tot_act += aux_der;
                    tot_act = tot_act - (derecha.front() - 1);
                    derecha.pop();
                }else{
                    miradas[izquierda.front()] = 'L';
                    tot_act += aux_izq;
                    tot_act = tot_act - (n - izquierda.front());
                    izquierda.pop();
                }
                cout << tot_act << " ";
                k++;
            }
        }
        for(int i = k; i <= n; i++) cout << tot_act << " ";
        cout << "\n";
    }
    return 0;
}