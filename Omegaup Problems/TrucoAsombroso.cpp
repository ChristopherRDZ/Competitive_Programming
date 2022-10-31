/// Problem Link: https://omegaup.com/arena/problem/OMI-2017-Operaciones/
/// Greedy problem - OMI2017

#include <iostream>
using namespace std;

char b[1000002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n=0,aux=0,r=0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>b[i];
    }
    if (n>2){
       for (int i=n-1;i>1;i--){
           if ((b[i-1]=='1')&&(b[i]=='0')){
               aux+=1;
           }
           if ((b[i-1]=='0')&&(b[i]=='1')){
               aux+=2;
           }
           if ((b[i-1]=='0')&&(b[i]=='0')){
               aux+=1;
           }
           if ((b[i-1]=='1')&&(b[i]=='1')){
               aux+=2;
               r=i;
               while(b[r]=='1'){
                   if (b[r]=='1'){
                       b[r]='0';
                       r--;
                   }
               }
               b[r]='1';
           }
       }
       if ((b[0]=='1')&&(b[1]=='0')){
           cout<<aux+1;
       }else{
           cout<<aux+2;
       }
   }else{
       if ((b[0]=='1')&&(b[1]=='0')){
          cout<<aux+1;
       }else{
          cout<<aux+2;
       }
   }

   return 0;
}