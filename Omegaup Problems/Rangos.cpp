/// Problem Link: https://omegaup.com/arena/problem/rangos/
/// OMI 2009

#include <iostream>
using namespace std;

struct rango{
   long long int ini,fin;
};
rango ac[1002];

long long int calcularsuma(long long int vi,long long int vf){
   long long int x = vf*(vf+1)/2;
   long long int y = (vi-1) * vi/2;
   return (x - y + 10000) % 10000;
}

rango obtenervivf(long long int i,long long f,long long o){
   long long int A=ac[o].ini,B=ac[o].fin;
   rango vivf;
   if (f<A || i>B){
      vivf.ini=0;
      vivf.fin=0;
   }else if(i>=A && f<=B){
      vivf.ini=i-A+1;
      vivf.fin=vivf.ini+(f-i);
   }else if (i<A && f>=A && f<=B){
      vivf.ini=1;
      vivf.fin=1+(f-A);
   }else if (f>B && i>=A && i<=B){
      vivf.ini=1+(i-A);
      vivf.fin=vivf.ini+(B-i);
   }else if (i<A && f>B){
      vivf.ini=1;
      vivf.fin=1+(B-A);
   }
   return vivf;
}

long long int probar (long long int i,long long int f, long long o){
   rango v=obtenervivf(i,f,o);
   long long int suma=calcularsuma (v.ini,v.fin);
   return suma;
}

int main ()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,a,p;
   cin>>n>>a>>p;
   for (int i=0;i<a;i++){
      cin>>ac[i].ini;
      cin>>ac[i].fin;
   }
   for (int j=0;j<p;j++){
      long long int i,f,solucion=0;
      cin>>i>>f;
      for (int o=0;o<a;o++){
         long long int respuesta=probar(i,f,o);
         solucion+=respuesta;
         solucion%=10000;
      }
      cout<<solucion<<endl;
   }

   return 0;
}