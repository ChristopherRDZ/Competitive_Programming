/// Problem Link: https://omegaup.com/arena/problem/OMI-2020-Ovejas
/// Binary Search + Prefix Sum 2D array (One of my favorite problems)

#include <bits/stdc++.h>

using namespace std;

int ovejas[1005][1005];

int main()

{

    ios_base::sync_with_stdio(0); cin.tie(0);

    cout.tie(0);

    int n, q, cuantas;

    short int x, y, x2, y2, x1, y1, ini, fin, mit;

    short int  pasos;

    cin >> n >> q;

    for (int i = 1; i <= n; i++){

        cin >> x >> y;

        x++;

        y++;

        ovejas[y][x] = 1;

    }

    for (int i = 1; i <= 1001; i++){

        for (int j = 1; j <= 1001; j++){

                ovejas[i][j] = ovejas[i][j] + ovejas[i][j-1] + ovejas[i-1][j] - ovejas[i-1][j-1];

        }

    }

    for (int i = 1; i <= q; i++){

        cin >> x >> y;

        x++;

        y++;

        ini = 0;

        fin = 1000;

        while (ini <= fin){

            mit = (ini + fin) / 2;

            x1 = min(1001, x + mit);

            y1 = min(1001, y + mit);

            x2 = max(1, x - mit);

            y2 = max(1, y - mit);

            cuantas = ovejas[y1][x1] - ovejas[y1][x2-1] - ovejas[y2-1][x1] + ovejas[y2-1][x2-1];

            if (cuantas > 0){

                fin = mit - 1;

                pasos = mit;

            }else{

                ini = mit + 1;

            }

        }

        cout << pasos << "\n";

    }

    return 0;

}