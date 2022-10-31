/// Problem Link: https://omegaup.com/arena/problem/Ordenando-Digitos
/// Bucket sorting

#include <iostream>

using namespace std;

int a[1000002];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int x,y, mayor = 0;
    cin>>x;

    for (int i=0;i<x;i++){
        cin>>y;
        if (y > mayor) mayor = y;
        a[y]++;

    }

    for (int i=0;i<=mayor;i++){
        if (a[i]>0){
            for (int j=0;j<a[i];j++){
                cout<<i<<" ";
            }
        }
    }

    return 0;
}