#include <bits/stdc++.h>
using namespace std;

int cubeta[503];

vector <char> uno;
vector <char> dos;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test;
    cin >> test;

    while(test--){
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++){
            cubeta[s[i]]++;
        }
        for (int i = 0; i <= 200; i++){
            if (cubeta[i] == 1){
                char aux = i;
                uno.push_back(aux);
            }
            if (cubeta[i] == 2){
                char aux = i;
                dos.push_back(aux);
                dos.push_back(aux);
            }
        }
        for (auto x: uno) cout << x;
        for (auto x: dos) cout << x;
        cout << "\n";
        for (int i = 0; i <= 200; i++) cubeta[i] = 0;
        uno.clear();
        dos.clear();

    }
    return 0;
}