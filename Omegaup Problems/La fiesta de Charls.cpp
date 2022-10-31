///Problem Link: https://omegaup.com/arena/problem/OMI2018-CDMX-EDOMEX-1

#include <bits/stdc++.h>

using namespace std;

long long int c[100002];

int main (){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long int x, y, z, s;

    cin>>x;

    for (int i=0;i<x;i++)
        cin>>c[i];

    sort (c,c+x);

    z=x/2;
    for (int i=0;i<x;i++){
        y=abs (c[z] - c[i]);
        s+=y;
    }

    cout<<s;
    return 0;
}