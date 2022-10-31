#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

struct dato{
    int indice;
    long long int valor;
};

bool operator <(const dato&a, const dato&b){
    if(a.valor < b.valor) return true;
    return false;
}

struct ura{
    int indice;
    long long int valor;
};

bool operator <(const ura&a, const ura&b){
    if(a.indice < b.indice) return true;
    return false;
}

int nums[200005];
dato pre[200005];
ura resp[200005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, q, aux;
        cin >> n >> q;
        for (int i = 1; i <= n; i++){
            cin >> nums[i];
        }

        for (int i = 1; i <= q; i++){
            cin >> aux;
            pre[i].indice = i;
            pre[i].valor = aux;
        }
        sort(pre + 1, pre + q + 1);

        long long int sum = 0, pos_aux = 1;
        nums[n + 1] = INT_MAX;
        for (int i = 1; i <= q; i++){
            while(pre[i].valor >= nums[pos_aux]){
                sum += nums[pos_aux];
                pos_aux++;
            }
            resp[i].indice = pre[i].indice;
            resp[i].valor = sum;
        }
        sort(resp + 1, resp + q + 1);
        for (int i = 1; i <= q; i++){
            cout << resp[i].valor << " ";
        }
        cout << "\n";
    }

    return 0;
}