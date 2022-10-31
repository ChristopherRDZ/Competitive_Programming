#include <bits/stdc++.h>
using namespace std;

#define fr(x) for (int i = 1; i <= x; i++)
#define debug(x) cout << x << "\n"
typedef long long int ll;

char arre[200005];
int cubeta[30];
vector <int> posis[30];
int respuesta[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;

        cin >> s;
        for (int i = 0; i < s.size(); i++) cubeta[s[i] - 'a' + 1]++;
        for (int i = 0; i < s.size(); i++)
            posis[s[i] - 'a' + 1].push_back(i);

        int tam = s.size() - 1, ini = s[0] - 'a' + 1;
        int fin = s[tam] - 'a' + 1;
        int pos_aux = 1, tot = 0;
        if(ini >= fin){

            int ant = ini;
            for (int i = ini; i >= fin; i--){
                if (cubeta[i] > 0){
                    tot = tot + (ant - i);
                    ant = i;
                }

                int ya = 0;
                while(cubeta[i] > 0){
                    respuesta[pos_aux] = posis[i][ya++];
                    cubeta[i]--;
                    pos_aux++;
                }
            }

            cout << tot << " " << pos_aux - 1 << "\n";
            for (int i = 1; i < pos_aux; i++) cout << respuesta[i] + 1 << " ";
        }else{
            int ant = fin, ya;
            for (int i = fin; i >= ini; i--){
                if (cubeta[i] > 0){
                    tot = tot + (ant - i);
                    ant = i;
                    ya = posis[i].size() - 1;
                }

                while(cubeta[i] > 0){
                    respuesta[pos_aux] = posis[i][ya--];
                    cubeta[i]--;
                    pos_aux++;
                }
            }

            cout << tot << " " << pos_aux - 1 << "\n";
            for (int i = pos_aux - 1; i >= 1; i--) cout << respuesta[i] + 1 << " ";
        }

        for(int i = 0; i <= 28; i++){
            cubeta[i] = 0;
            posis[i].clear();
        }

        cout << "\n";
    }
    return 0;
}