#include <iostream>
using namespace std;

long long solve(int n) {
	long long a[n+1] = {1};
	for(int i = 1; i <= n; i++) {
		int x = max(i-3, 0);
		for(x; x < i; x++)
			a[i] += a[x];
	}
	return a[n];
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		cout << solve(n) << endl;
	}
}
