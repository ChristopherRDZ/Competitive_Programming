/// Problem Link: https://omegaup.com/arena/problem/Precios
/// Implemantation problem

#include <iostream>

using namespace std;

int main()
{
    char num1[202];
    char num2[202];
    int x,a,b,r=0,mayor=0,menor=0,aux=0,c=0,o=0;
    cin>>x;
    for (int i=0;i<x;i++){
        cin>>num1[i];
    }
    for (int i=0;i<x;i++){
        cin>>num2[i];
    }
    for (int i=0;i<x; i++){
        a = num1[i];
        b = num2[i];
        if (a>b){
            mayor = a;
            menor = b;
            r = mayor - menor;
            if (r > 5){
                aux = r - 5;
                o = 5 - aux;
                c = c + o;
            }else{
                c = c + r;
            }
        }
        if (b>a){
            mayor = b;
            menor = a;
            r = mayor - menor;
            if (r > 5){
                aux = r -5 ;
                o = 5 - aux;
                c = c + o;
            }else{
                c = c + r;
            }
        }
    }
    cout << c;
    return 0;
}