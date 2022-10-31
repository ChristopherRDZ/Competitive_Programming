#include <iostream>

using namespace std;

int main()
{
    int t, n, k, aux;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> n >> k;
        aux = 0;
        while (aux < n){
            cout << 'a';
            aux++;
            if (aux >= n )
                break;
            cout << 'b';
            aux++;
            if (aux >= n)
                break;
            cout << 'c';
            aux++;
            if (aux >= n)
                break;
        }
        cout << "\n";
    }
    return 0;
}