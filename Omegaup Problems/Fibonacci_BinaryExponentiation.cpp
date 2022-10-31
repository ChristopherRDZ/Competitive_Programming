/// Problem Link: https://omegaup.com/arena/problem/modfib
/// Binary Exponentiation, Fibonacci O(logN), power of the matrix

#include <iostream>
using namespace std;

long long int n, m, a, b, c, d;
long long int matriz[2][2] = { {0, 1}, {1, 1} };
long long int aux[2][2] = { {0, 1}, {1, 1} };

void multi(long long int ma[2][2], long long int aux[2][2]){
	a = (ma[0][0] * aux[0][0]) % m + (ma[0][1] * aux[1][0]) % m;	
	b = (ma[0][0] * aux[0][1]) % m + (ma[0][1] * aux[1][1]) % m;
	c = (ma[1][0] * aux[0][0]) % m + (ma[1][1] * aux[1][0]) % m;
	d = (ma[1][0] * aux[0][1]) % m + (ma[1][1] * aux[1][1]) % m;
	matriz[0][0] = a;
	matriz[0][1] = b;
	matriz[1][0] = c;
	matriz[1][1] = d;
}

void binpow(long long int ma[2][2], int n){
	if (n == 1) return;
	binpow(ma, n / 2);	
	multi(ma, ma);
	if (n % 2 == 1){
		multi(ma, aux);
	}
}

int main(){
	cin >> n >> m;
	if (n == 0){
		cout << 0;
	}else{
		binpow(matriz, n);
		cout << matriz[0][1];
	}
	return 0;
}