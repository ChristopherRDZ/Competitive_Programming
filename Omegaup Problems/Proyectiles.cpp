/// Problem Link: https://omegaup.com/arena/problem/Proyectiles 
/// Binary Search

#include <bits/stdc++.h>

using namespace std;

struct coordenadas{
    int x;
    int y;
};

bool operator<(const coordenadas&a, const coordenadas&b){
    if (a.x<b.x){
        return true;
    }else{
        return false;
    }
    if (a.x==b.x){
        if (a.y<b.y){
            return true;
        }else{
            return false;
        }
    }
}

coordenadas naves[100002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    int x1,y1;
    int ini=0,fin=0,mit=0;
    int aux=0;
    int rec=0;
    bool comprobar = false;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>naves[i].x;
        cin>>naves[i].y;
    }
    sort (naves+0,naves+n);
    for (int i=0;i<k;i++){
        cin>>x1>>y1;
        ini=0;
        fin=n-1;
        comprobar = false;
        rec = 0;
        aux = 0;
        while (ini <= fin){
            mit = (ini + fin)/2;
            if (naves[mit].x < x1){
                ini = mit + 1;
            }
            if (naves[mit].x > x1){
                fin = mit - 1;
            }
            if (naves[mit].x == x1){
                aux = naves[mit].x;
                rec = mit;
                while (naves[rec].x == aux){
                    rec = rec - 1;
                    if (rec<0){
                        break;
                    }
                }
                rec = rec + 1;
                while (naves[rec].x == aux){
                    if (naves[rec].y == y1){
                        comprobar = true;
                        break;
                    }
                    rec++;
                    if (rec==n){
                        break;
                    }
                }
                break;
            }
        }
        if (comprobar == false){
            cout << 1 << "\n";
        }else{
            cout << 0 << "\n";
        }
    }
    return 0;
}

