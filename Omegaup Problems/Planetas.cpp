/// Problem Link: https://omegaup.com/arena/problem/Planetas
/// Binary Search

#include <bits/stdc++.h>

using namespace std;

double planeta[1002];

int n;

double Fuerza(int de, int a, double meteoro){

    double ret_val=0;

       for(int i =de ; i<=a;i++){

          ret_val+=1/abs( (double) planeta[i]-meteoro);

       }

       return ret_val;

}

void meteoro(int anterior, int siguiente){

    double mitad, li, ls, izq,der;

    li=(double) planeta[anterior];

    ls=(double) planeta[siguiente];

    while (li<=ls){

          mitad=(li+ls)/2;

          izq=Fuerza(1,anterior,mitad);

          der=Fuerza(siguiente,n,mitad);

          if(izq==der){

            break;

          }

          if ( (izq-der) >0){

            li=mitad+.0000001;

          }else{

            ls=mitad-.0000001;

          }

    }

    cout << fixed << setprecision(3)<< mitad <<" ";

}

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cin >>n;

    for (int i=1;i<=n;i++){

        cin>> planeta[i];

    }

    sort(planeta+1,planeta+n+1);

    cout << n-1<<"\n";

    for (int i=1; i<n;i++){

        meteoro(i,i+1);

    }

    return 0;

}



