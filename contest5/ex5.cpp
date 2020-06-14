#include <iostream>
using namespace std;
int mod = 1000000000+7;

int solve(int k, int n) {
	int a[k+1][n+1] = {};
	for(int i = 0; i <= n; i++)
		a[0][i] = 1;
	for(int i = 1; i <= k; i++) {
		for(int j = i; j <= n; j++)
			a[i][j] = (a[i-1][j-1]%mod + a[i][j-1]%mod)%mod;
	}
	return a[k][n];
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, k; cin >> n >> k;
		cout << solve(k, n) << endl;
	}	
}
