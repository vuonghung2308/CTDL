#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
	int a[n+1] = {0, 1};
	for(int i = 2; i <= n; i++) {
		a[i] = 1 + a[i-1];
		for(int j = 2; j*j <= i; j++)
			a[i] = min(a[i], a[i-j*j] + 1);
	}
	return a[n];
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		cout << solve(n) << endl;
	}
}
