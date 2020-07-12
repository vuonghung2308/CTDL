#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		long long n, sum2 = 0; cin >> n;
		long long sum1 = (n*n + n) / 2;
		for(int i = 0; i < n-1; i++) {
			long long t; cin >> t;
			sum2 = sum2 + t;
		}
		cout << sum1 - sum2 << endl;
	}
}
