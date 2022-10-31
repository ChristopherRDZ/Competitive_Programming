/// Problem Link: https://omegaup.com/arena/problem/Matanza-de-Binarios
/// Implementation

#include <iostream>
using namespace std;

int binario[40];

int main(){

    int x,n,aux,i=0,r=0,a=0,f;

    cin>>x;

    for (int j=0;j<x;j++){
        cin>>n;

        f=n;
        i=0;
        r=0; 
        while(f>0){
            aux=f%2;
            f=f/2;
            binario[i]=aux;
            i++;
        }
        for (int q=0;q<i;q++){
            if (binario[q]==1){
                r++;
            }
        }
        if (r%2==1){
            a++;
        }
        r=0;
     }
     cout<<x-a;

     return 0;
}