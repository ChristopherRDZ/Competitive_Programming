#include <iostream>

using namespace std;

int num[102];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, n;
    cin >> x;
    for (int i = 1; i <= x; i++){
        cin >> num[i];
    }
    for (int i = 1; i <= x; i++){
        if (num[i] %2 == 0){
            for (int j = num[i]; j >= 1; j--){
                cout << j << " ";
            }
        }else{
            for (int j = num[i]; j >= 1; j--){
                if (j == (num[i] / 2) + 1){
                    cout << j - 1 << " ";
                }else{
                    if (j == num[i] / 2){
                        cout << j + 1 << " ";
                    }else{
                        cout << j << " ";
                    }
                }
            }
        }
        cout << "\n";
    }
    return 0;
}