/// Problem Link: https://omegaup.com/arena/problem/Carrera-de-Larga-Distancia
/// Implementation problem

#include <iostream>

using namespace std;

int main()

{

    ios_base::sync_with_stdio(0);cin.tie(0);

    int m,t,u,f,d,tot=0,r=0;
    char c;

    cin >> m >> t >> u >> f >> d;
    for (int i=0;i<t;i++){
        cin>>c;
        if (c=='U'){
            tot=tot+u+d;
        }
        if (c=='F'){
            tot=tot+f+f;
        }
        if (c=='D'){
            tot=tot+d+u;
        }
        if (tot<=m){
            r++;
        }
    }
    cout<<r;

    return 0;
}