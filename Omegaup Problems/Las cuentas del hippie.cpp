/// Problem Link: https://omegaup.com/arena/problem/cuentas
/// Sliding windows - OMI 2005

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c,n,a,b;
    int cuentas[30002],negras=0,otras=0,inicio,des;
    cin>>c;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>cuentas[i];
    }
    for (int i=0;i<n;i++){
        if (cuentas[i]==0){
            a=i;
            break;
        }
    }
    for (int i=a;i<n;i++){
        if (cuentas[i]==0){
            negras++;
            if (negras==c){
                    b=i;
                break;
            }
        }else{
            otras++;
        }
    }
    inicio=a;
    des=otras;
    do{
            do{
                a++;
                if (a==n){
                    a=0;
                }
                if (cuentas[a]!=0){
                    otras=otras-1;
                }
            }while(cuentas[a]!=0);
            do{
                b++;
                if (b==n){
                    b=0;
                }
                if (cuentas[b]!=0){
                    otras=otras+1;
                }
            }while(cuentas[b]!=0);
       if (otras<des){
        des=otras;
       }
    }while(a!=inicio);
    cout<<des;
    return 0;
}