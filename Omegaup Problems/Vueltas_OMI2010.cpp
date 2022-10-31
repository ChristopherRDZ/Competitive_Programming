/// Problem Link: https://omegaup.com/arena/problem/L-OMI2010-Vueltas
/// Implementation Problem OMI 2010

#include <bits/stdc++.h>

using namespace std;

int v[1002][1002];

int vo[1002][1002];

int vo2[1002][1002];

int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int m,n,c;

    int ch=0,cv=0;

    char a;

    int vh=0,vv=0;

    cin>>m>>n;

    for (int i=1;i<=m;i++){

        for (int j=1;j<=n;j++){

            cin>>v[i][j];

            vo[i][j]=v[i][j];

        }

    }

    cin>>c;

    for (int i=1;i<=c;i++){

        cin>>a;

        if (a == 'H'){

            ch++;

        }

        if (a == 'V'){

            cv++;

        }

    }

    if (ch %2 == 1){

        vh = 1;

    }

    if (cv %2 == 1){

        vv = 1;

    }

    if (vh == 1){

        for (int i=1;i<=m;i++){

            for (int j=1;j<=n;j++){

                v[i][j]=vo[i][n+1-j];

                vo2[i][j]=v[i][j];

            }

        }

    }

    if (vv == 1){

        if (vh == 1){

            for (int i=1;i<=m;i++){

                for (int j=1;j<=n;j++){

                    v[i][j]=vo2[m+1-i][j];

                }

            }

        }

        if (vh == 0){

            for (int i=1;i<=m;i++){

                for (int j=1;j<=n;j++){

                    v[i][j]=vo[m+1-i][j];

                }

            }

        }

    }

    for (int i=1;i<=m;i++){

        for (int j=1;j<=n;j++){

            cout<<v[i][j]<<" ";

        }

        cout<<"\n";

    }

    return 0;

        

}


