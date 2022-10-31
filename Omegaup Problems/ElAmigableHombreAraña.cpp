/// Problem Link: https://omegaup.com/arena/problem/OMI-2019-Spider-Man
/// OMI 2019

#include <iostream>
using namespace std;

int main()

{

    long long int n,m,k,x,y,mx,my,s=0,r=0,d,f;

    cin>>n>>m>>k>>x>>y;

    f = (x*(m-1) + y) * n;

    if (x>k && y>k){

        cout<<1;

    }else{

      if (k>=f){

          cout<<n*m;

      }else{

        if (x==y){

          if (x==1 && y ==1){

              cout<<k+1;

          }else{

          cout<<(k/y)+1;

          }
        }

        my=(y*(n-1))+x;
        mx=(x*(m-1))+y;

        if (x<y){

            if (k%mx==0){

                d = k/mx;

                r = (d * m) + 1;

                cout<<r;

            }else{

                d = k/mx;

                r = (d * mx);

                r = k - r;

                r = r / x;

                if (r>=m){

                    r=m;

                    s = (d * m) + r;

                    cout<<s;

                }else{

                    s = (d * m) + r + 1;

                    cout<<s;

                }
            }
        }

        if (y<x){

            if (k%my==0){

                d = k/my;

                r = (d * n) + 1;

                cout<<r;

            }else{

                d = k/my;

                r = (d * my);

                r = k - r;

                r = r / y;

                s = (d * n) + r + 1;

                cout<<s;

            }
        }
      }
    }

    return 0;
}