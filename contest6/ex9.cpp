#include <bits/stdc++.h>
using namespace std;

int countPair(int na, int k, int *a) {
	sort(a, a+na); int count = 0;
	for(int i = na-1; i > 0; i--) {
		int t = k - a[i];
		for(int j = i-1; j >= 0 && a[j] >= t; j--)
			if(t == a[j]) count = count + 1;
	}
	return count;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, k; cin >> n >> k;
		int a[n], na = 0;
		for(int i = 0; i < n; i++) {
			int t; cin >> t;
			if(t <= k) {
				a[na++] = t;
			}
		}
		cout << countPair(na, k, a) << endl;
	}
}
