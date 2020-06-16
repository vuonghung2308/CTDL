#include <iostream>
using namespace std;

long long solve(int n, int m) {
	long long c[n+1][m+1] = {};

	for(int i = 0; i <= m; i++)
		c[n][i] = 1;
	for(int i = 0; i <= n; i++)
		c[i][m] = 1;
		
	for(int i = n-1; i >= 0; i--)
		for(int j = m-1; j >= 0; j--)
			c[i][j] = c[i+1][j] + c[i][j+1];

	return c[0][0];
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int m, n; cin >> n >> m;
		cout << solve(n, m) << endl;
	}
}
