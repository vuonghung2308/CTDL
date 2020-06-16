#include <bits/stdc++.h>
using namespace std;

int solve(int *a, int *a_, int n) {
	int c[n+1][n+1] = {};
	sort(a_, a_+n);
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			if(a[i-1] == a_[j-1]) c[i][j] = c[i-1][j-1]+1;
			else c[i][j] = max(c[i-1][j], c[i][j-1]);
	}
	
	return n - c[n][n];
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int *a =  new int[n];
		int *a_ = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			a_[i] = a[i];
		}
		cout << solve(a, a_, n) << endl;
	}
}
