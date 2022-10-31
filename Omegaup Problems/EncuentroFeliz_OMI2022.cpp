/// Problem Link: https://omegaup.com/arena/problem/omi-2022-feliz-encuentro/
/// Prefix Sum (OMI 2022)

#include <iostream>

using namespace std;

int acum[100005];

int main(){

	ios_base::sync_with_stdio(0); cin.tie(0);	int n, q;

	cin >> n >> q;

	char ant = ';', aux;

	int tot = 0;

	for (int i = 1; i <= n; i++){

		cin >> aux;

		if(aux == ant) tot++;

		ant = aux;

		acum[i] = tot;

	}

	for (int i = 1; i <= q; i++){

		int a, b;

		cin >> a >> b;

		int res = acum[b] - acum[a];

		cout << res << "\n";

	}

	return 0;

}