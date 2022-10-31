/// Problem Link: https://omegaup.com/arena/problem/Vacaciones-Reloaded
/// Sliding Windows
#include <iostream>

using namespace std;

long long int v[100002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int acumulado=0,lugares=1,mayor_d=0,mayor_i=0;
    long long int n,k;
    long long int i=0,j=0;
    bool comprobar=false;
    long long int origen=0;
    long long int formula=0;
    bool todo =false;

    cin>>n>>k;
    for (int f=1;f<=n;f++){
        cin>>v[f];
        if (v[f]<=k){
            comprobar=true;
        }
    }
    if (comprobar==false){
        cout<<-1;
    }else{
        //Lado Derecho
        for (int f=1;f<=n;f++){
            if (v[f]<=k){
                i = f;
                j = f;
                origen= f;
                break;
            }
        }
        lugares = 1;
        acumulado=v[i];
        mayor_d = acumulado;
        formula = lugares*k;
        while(acumulado<=formula){
            j++;
            if (j>n){
                j = 1;
            }
            acumulado=acumulado+v[j];
            lugares++;
            formula = lugares*k;
            if (acumulado<=formula){
                if (acumulado>mayor_d){
                    mayor_d=acumulado;
                    if (lugares==n){
                        todo = true;
                        break;
                    }
                }
            }
        }
        if (todo == false){
        while (1==1){
            if (acumulado<=formula){
                j++;
                if (j>n){
                    j = 1;
                }
                acumulado = acumulado + v[j];
                lugares ++;
                formula = lugares * k;
                if (v[i]<=k){
                    if (acumulado<=formula){
                        if (acumulado>mayor_d){
                            mayor_d=acumulado;
                            if (lugares==n){
                                break;
                            }
                        }
                    }
                }
            }else{
                if (i == j){
                    i++;
                    j++;
                    if (i>n){
                        i = 1;
                        j = 1;
                    }
                    acumulado = v[i];
                    lugares = 1;
                    formula = lugares * k;
                }else{
                    acumulado = acumulado - v[i];
                    i++;
                    if (i>n){
                        i = 1;
                    }
                    lugares--;
                    formula = lugares*k;
                }
            }
            if (i==origen){
                break;
            }
        }
        //Lado Izquierdo
        formula = 0;
        origen = 0;
        j = 0;
        i = 0;
        lugares = 1;
        acumulado = 0;
        for (int f=n;f>=1;f--){
            if (v[f]<=k){
                i = f;
                j = f;
                origen= f;
                break;
            }
        }
        lugares = 1;
        acumulado=v[i];
        mayor_i = acumulado;
        formula = lugares * k;
        while(acumulado<=formula){
            j--;
            if (j==0){
                j = n;
            }
            acumulado=acumulado+v[j];
            lugares++;
            formula = lugares * k;
            if (acumulado<=formula){
                if (acumulado>mayor_i){
                    mayor_i=acumulado;
                    if (lugares==n){
                        break;
                    }
                }
            }
        }
        while (1==1){
            if (acumulado<=formula){
                j--;
                if (j==0){
                    j = n;
                }
                acumulado = acumulado + v[j];
                lugares ++;
                formula = lugares * k;
                if (v[i]<=k){
                    if (acumulado<=formula){
                        if (acumulado>mayor_i){
                            mayor_i = acumulado;
                            if (lugares==n){
                                break;
                            }
                        }
                    }
                }
            }else{
                if (i == j){
                    i--;
                    j--;
                    if (i==0){
                        i = n;
                        j = n;
                    }
                    acumulado = v[i];
                    lugares = 1;
                    formula = lugares * k;
                }else{
                    acumulado = acumulado - v[i];
                    i--;
                    if (i==0){
                        i = n;
                    }
                    lugares--;
                    formula = lugares * k;
                }
            }
            if (i==origen){
                break;
            }
        }
        if (mayor_d>=mayor_i){
            cout<<mayor_d;
        }else{
            cout<<mayor_i;
        }
    }else{
        cout<<mayor_d;
    }
    }
    return 0;
}



