#include <iostream>
using namespace std;

long long int binExp(int a, int n){
	if (n == 1) return a;
	long long int x = binExp(a, n/2);
	x *= x;
	x %= 998244353;
	if (n&1){
		x *= a;
		x %= 998244353;
	}
	return x;
}

int main(){
	int n, m;
	cin >> n >> m;
	long long int ans = 1;
	int k = n + m;
	ans = binExp(2, k);
	cout << ans <<"\n";
}