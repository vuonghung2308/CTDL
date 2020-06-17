#include <iostream>
using namespace std;

int solve(int *a, int n, int c) {
	int w[c+1][n+1] = {};
	for(int i = 1; i <= c; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[j-1] <= i) 
				w[i][j] = max(a[j-1] + w[i-a[j-1]][j-1], w[i][j-1]);
			else w[i][j] = w[i][j-1];
		}
	}
	return w[c][n];
}

int main() {
		int c, n; cin >> c >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << solve(a, n, c);
}
