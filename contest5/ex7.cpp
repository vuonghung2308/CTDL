#include <iostream>
using namespace std;

int mod = 1000000000+7;

int solve(int n, int k) {
	int a[n+2] = {};
	a[1] = 1;
	
	for(int i = 2; i <= n+1; i++) {
		int x = max(i-k, 0);
		for(int j = x; j < i; j++)
			a[i] = (a[j]%mod + a[i])%mod;
	}
	return a[n+1];
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, k; cin >> n >> k;
		cout << solve(n, k) << endl;
	}
}
