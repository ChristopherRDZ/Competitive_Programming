/// Problem Link: https://omegaup.com/arena/problem/Defendiendo-el-Castillo
/// Binary Search (One of my favorite problems)

#include <bits/stdc++.h>
using namespace std;

int  n, radio;
long long int k;
long long int  a[500002];   /// almacenar los arqueros
long long int  r[500002];   /// su intervalo de afecatcion
long long int  in[500002];
long long int  f[500002];
long long int  c[500002];

long long int NivelSeguridad=0;

void PreCalculo(){
   for (int i=1; i<=n;i++){
       in[max(1,i-radio)]+=a[i];
       f[min(n,i+radio)]+=a[i];
   }
   for (int i=1;i<=n;i++){
       r[i]=r[i-1]+in[i]-f[i-1];
   }

}

/// limite si puedo alcanar ese limite conlos arqueros /o guradias adicionales
/// si puede alcanzar la altura debe regresa un valor >=0
/// si no la pruede lacanzar que regrese -1
long long int verificar(long long int Limite){

  long long int Nivel=0,Guardias=0, GFaltan=0, GDisponibles=0;
  long long int ret_val=Limite; // la inialice al limite
  GDisponibles=k;


  for(int i=1; i<=n;i++){
       Nivel=Guardias + r[i];
       if(Nivel <=Limite){
          /// acompleto el nievel
         GFaltan=Limite-Nivel;
         if (GFaltan > GDisponibles){
              ret_val=-1;
         } else{
             /// si me alcanzan los guardias
             GDisponibles-=GFaltan;
             Guardias+=GFaltan;
             /// marcan donde se va a descontar
             c[min(n,i+(2*radio))]+=GFaltan;
         }

       }
       /// elimino los guardias vencidos en la posiicon i
       Guardias-=c[i];
       /// lo dejo en ceros para la siegute pregunta de
       /// la busqueda binaria
     c[i]=0;
  }
  return ret_val;
}

long long int binaria(long long int li, long long int ls){
  long long int  medio=0, altura=0;
  while(li<=ls){
    medio = (li + ls) / 2;
    altura=verificar(medio);
    if (altura==-1){
			ls=medio-1;
    } else{
    	if(altura>NivelSeguridad){
    		NivelSeguridad=altura;
    	}
      li=medio+1;
    }
  }
   return NivelSeguridad;
}

int main(){
      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      ///
      cin  >> n >> radio >> k;
  		for(int i = 1; i <= n; ++i){
      	cin >> a[i];
      }
      PreCalculo();
      cout << binaria(0,LLONG_MAX);
      return 0;
}
