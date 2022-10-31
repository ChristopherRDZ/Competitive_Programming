#include <bits/stdc++.h>
using namespace std;
int a[110];

int main()
{
    int n,t;
    bool si=true;
    cin>>n;
    while(n--){
      si = true;
      cin>>t;
      for(int i=0; i<t; i++){
        cin>>a[i];
      }
      sort(a+0, a+t);

      for(int j=0; j < t - 1; j++){
        if(a[j]==a[j+1]){
          cout<<"NO\n";
          si=false;
          break;
        }
      }
      
      if(si){
        cout<<"YES\n";
      }
    }

    return 0;
}