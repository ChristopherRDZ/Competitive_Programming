#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

ll bucket_s[50];
ll bucket_t[50];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int q, d, k;
        string aux;
        cin >> q;

        bucket_s[1] = 1;
        bucket_t[1] = 1;
        for (int i = 1; i <= q; i++){
            cin >> d >> k >> aux;
            if(d == 1){
                for (int j = 0; j < aux.size(); j++){
                    char letra = aux[j] - 'a' + 1;
                    bucket_s[letra] += k;
                }
            }
            if(d == 2){
                for (int j = 0; j < aux.size(); j++){
                    char letra = aux[j] - 'a' + 1;
                    bucket_t[letra] += k;
                }
            }

            bool tiene_t = false;
            for (int j = 2; j <= 26; j++){
                if(bucket_t[j] > 0){
                    tiene_t = true;
                    break;
                }
            }
            if(tiene_t){
                cout << "YES";
            }else{
                bool tiene_s = false;
                for (int j = 2; j <= 26; j++){
                    if(bucket_s[j] > 0){
                        tiene_s = true;
                        break;
                    }
                }
                if(tiene_s){
                    cout << "NO";
                }else{
                    if(bucket_s[1] < bucket_t[1]) cout << "YES";
                    else cout << "NO";
                }
            }
            cout << "\n";
        }
        for (int i = 0; i <= 30; i++){
            bucket_s[i] = 0;
            bucket_t[i] = 0;
        }
    }

    return 0;
}