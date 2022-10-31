/// Problem Link:  https://omegaup.com/arena/problem/omi-2022-frase-oculta
/// Binary Search (OMI 2022)

#include <iostream>
#include <vector>

using namespace std;
vector <int> indices[30];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

	int t, q, n;
	cin >> t >> q;

	for (int i = 1; i <= t; i++){
		char aux;
		cin >> aux;
		indices[aux - 'a'].push_back(i);
	}

	for (int i = 1; i <= q; i++){
		cin >> n;

		bool pudo = true;
		int ant = -1;
		for (int j = 1; j <= n; j++){
			char aux;
			cin >> aux;

			int posi = aux - 'a', primero = 100000000;
			bool meti = false;

			if (indices[posi].size() == 0 || !pudo){
				pudo = false;
			}else{
				int ini = 0, fin = indices[posi].size()-1;
				while(ini <= fin){

					int mit = (ini + fin) / 2;
					if(indices[posi][mit] <= ant)
						ini = mit + 1;
					if(indices[posi][mit] > ant){
						meti = true;
						if(indices[posi][mit] < primero)
							primero = indices[posi][mit];
						fin = mit - 1;
					}

				}
			}
      
			if(primero < ant){
				 pudo = false;
			}
			else{
				if (meti) ant = primero;
				else pudo = false;
			}
		}

		if(pudo) cout << "1\n";
		else cout << "0\n";

	}
	return 0;
}