#include <bits/stdc++.h>
using namespace std;

int qac(int n, long long k) {
	if(k == (long long) pow(2, n-1))
		return n;
	if(k < (long long) pow(2, n-1))
		return qac(n-1, k);
	return qac(n-1, (long long)pow(2, n)-k);
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; long long k;
		cin >> n >> k;
		cout << qac(n, k) <<endl;
	}
}
