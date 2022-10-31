#include <iostream>
using namespace std;

struct ura{
	int pos;
	int ter; 
};

struct dato{
	int ind;
	int emp;
};

ura p[1005];
dato fin[1005];
bool pinto[1005];

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		
		for(int i = 0; i <= 102; i++){
			p[i].pos = -1;
			p[i].ter = -1;
			pinto[i] = false;
		}
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			string x;
			cin >> x;
			for (int j = 0; j < s.size(); j++){
				int pos_aux = 0;
				if (s[j] == x[pos_aux]){
					int j2 = j;
					bool pudo = true;
					while(pos_aux < x.size()){
						if (s[j2] != x[pos_aux])
							pudo = false;
						pos_aux++;
						j2++;	
					}
					if(pudo){
						int aux = j + x.size() - 1;
						if(p[j].ter < aux){
							p[j].ter = aux;
							p[j].pos = i;
						}
					}
				}
			}
		}
		
		int act = -1, res = 0;
		int maxi = -100;
		int x, y;
		bool entro = false;
		for(int i = 0; i < s.size(); i++){
			if(i > act){
				if(entro){
					if(maxi >= p[i].ter){
						entro = false;
						res++;
						fin[res].ind = x;
						fin[res].emp = y;
						for(int j = i; j <= maxi; j++)
							pinto[j] = true;
						act = maxi;
						maxi = -100;
					}else{
						res++;
						fin[res].ind = p[i].pos;
						fin[res].emp = i  + 1;
						for(int j = i; j <= p[i].ter; j++)
							pinto[j] = true;
						act = p[i].ter;
					}
				}
			}
			if(p[i].ter >= 0){
				if(i == act + 1){
					res++;
					fin[res].ind = p[i].pos;
					fin[res].emp = i  + 1;
					for(int j = i; j <= p[i].ter; j++)
						pinto[j] = true;
					act = p[i].ter;
				}else{
					if(p[i].ter > act){
						entro = true;
						if(p[i].ter > maxi){
							maxi = p[i].ter;
							x = p[i].pos;
							y = i + 1;
						}
					}
				}
			}
		}
		bool logro = true;
		for(int i = 0; i < s.size(); i++){
			if(pinto[i] == false) logro = false;
		}
		if(logro){
			cout << res << "\n";
			for(int i = 1; i <= res; i++){
				cout << fin[i].ind << " " << fin[i].emp;
				cout <<"\n";
			}
		}else{
			cout <<"-1\n";
		}
	}
	return 0;
}