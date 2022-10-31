/// Problem Link: https://omegaup.com/arena/problem/iCop/
/// Implentation problem

#include <iostream>
using namespace std;

int valor[1002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,t,m=0,c=0;
    int d=0,r=0,a=0;
    cin>>n>>t;
    for (int i=1;i<=n;i++){
        cin>>valor[i];
    }
    for (int i=0;i<t;i++){
        for (int j=1;j<=n;j++){
            if (valor[j]>m){
                m = valor[j];
                c = j;
            }
        }
        d = valor[c] / (n-1);
        r = valor[c] % (n-1);
        cout<<c;
        valor[c] = 0;
        for (int h=1;h<=n;h++){
            if (h!=c){
                valor[h]+=d;
                if (a<r){
                    valor[h]=valor[h]+1;;
                    a++;
                }
            }
        }
        m = 0;
        c = 0;
        d = 0;
        r = 0;
        a = 0;
        /*
        for (int w=1;w<=n;w++){
            cout<<valor[w]<<" ";
        }
        */
        cout<<"\n";
    }
    return 0;
}