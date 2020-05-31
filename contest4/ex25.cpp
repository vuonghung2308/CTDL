#include <bits/stdc++.h>
using namespace std;

char qac(int n, long long k, long long *x) {
	if(n == 1 && k == 1) return 'A';
	if(n == 2 && k == 1) return 'B';
	if(k <= x[n-2]) return qac(n-2, k, x);
	return qac(n-1, k - x[n-2], x);
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; long long k;
		cin >> n >> k;
		long long *x = new long long[n+1];
		x[0]= 0; x[1] = 1;
		for(int i = 2; i <= n; i++)
			x[i] = x[i-2] + x[i-1];
		cout << qac(n, k, x) << endl;
	}
}
