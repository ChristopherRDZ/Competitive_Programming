/// Problem Link: https://omegaup.com/arena/problem/Musical
/// Buckets

#include <iostream>

using namespace std;

int cub[100002];

int main()
{
    int n,q,p[1003],aux=0,dig;
    cin>>n>>q;
    for (int i=0;i<n;i++){
        cin>>dig;
        for (int j=0;j<dig;j++){
            cub[aux]=i+1;
            aux++;
        }
    }
    for (int i=0;i<q;i++){
        cin>>p[i];
    }
    for (int i=0;i<q;i++){
        cout<<cub[p[i]]<<endl;
    }

    return 0;
}