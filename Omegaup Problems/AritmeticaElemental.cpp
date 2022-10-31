/// Problem Link: https://omegaup.com/arena/problem/2016-Aritmetica-Elemental


#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x,y,a=0;

  cin>>x>>y;

  int aux = 0;
  
  while(x!=0 || y!=0){
    if((x%10)+(y%10) + aux >9){
      aux = 1;
      a++;
    }else{
      aux = 0;
    }
    x/=10;
    y/=10;
  }    

  cout << a;
  return 0;
}