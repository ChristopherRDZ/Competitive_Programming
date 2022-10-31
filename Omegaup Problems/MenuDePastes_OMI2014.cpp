/// Problem Link: https://omegaup.com/arena/problem/OMI2014LENGUAJE1
/// Ad hoc Problem

#include <bits/stdc++.h>

using namespace std;

long long int pastes[1002];

long long int r1, r2, r3, r4, r5;

long long int final, total;

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    long long int m, n, p;

    cin >> m >> n;

    cin >> p;

    total = m * n;

    for (int i=0;i<p;i++){

        cin >> pastes[i];

    }

    for (int i=0;i<p;i++){

        if (pastes[i] % m == 0){

            r1 = pastes[i] / m;

        }else{

            r1 = (pastes[i] / m) + 1;

        }

        r2 = n - r1;

        r3 = total - r2;

        if (pastes[i] == ((r1 - 1) * m + 1)){

            r4 = 0;

        }else{

            r4=pastes[i] - ((r1 - 1) * m + 1);

        }

        r5 = r4 * n;

        final = r3 - r5;

        cout << final << " ";

    }

    return 0;

}



