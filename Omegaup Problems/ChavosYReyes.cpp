/// Problem Link: https://omegaup.com/arena/problem/Chavos-y-Reyes

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n,q,k,a,b,r=0,s1=0,s2=0;
    cin>>n>>q>>k;
    for (int i=0;i<q;i++){
        cin>>a>>b;
        s2=(b*(b+1))/2;
        s1=(a*(a-1))/2;
        r = s2-s1;
        if (r<k){
            cout << "Rey :(";
        }
        if (r==k){
            cout << "Tablas";
        }
        if (r>k){
            cout << "Chavos :)";
        }
        cout << "\n";
    }
    return 0;
}