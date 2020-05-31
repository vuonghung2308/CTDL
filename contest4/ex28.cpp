#include <bits/stdc++.h>
using namespace std;

int solve(int *a, int n) {
	int pairs = 0, j = n/2;
	for(int i = 0; i < n/2; i++) {
		while(a[i]*2 > a[j] && j < n) j++;
		if(j < n) {
			pairs = pairs + 1;
			j = j + 1;
		}
		if(j == n) break;
	}
	return n - pairs*2 + pairs;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n = 0; cin >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);
		cout << solve(a, n) << endl;
	}
}
