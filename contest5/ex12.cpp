#include <iostream>
using namespace std;
long long mod = 1000000000+7;

int solve(int n, int k) {
	if(k > n) return 0;
	long long res = 1;
	for(int i = n-k+1; i <= n; i++) {
		res = (res * i) % mod;
	}
	return res;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, k; cin >> n >> k;
		cout << solve(n, k) << endl;
	}
}
