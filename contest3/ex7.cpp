#include <bits/stdc++.h>
using namespace std;

long long greedy(long long *a, long long *b, int n) {
	long long x = 0;
	sort(a, a+n, greater<long long>());
	sort(b, b+n, less<long long>());
	for(int i = 0; i < n; i++)
		x = x + a[i] * b[i];
	return x;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		long long *a = new long long[n];
		long long *b = new long long[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n; i++)
			cin >> b[i];
		cout << greedy(a, b, n) << endl;
	}
}
