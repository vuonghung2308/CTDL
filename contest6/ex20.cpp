#include <bits/stdc++.h>
using namespace std;

int count(int *a, int n, int k) {
	sort(a, a+n);
	int c = 0;
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[j]-a[i] >= k)
				break;
			else c = c + 1;
		}
	}
	return c;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, k; cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << count(a, n, k) << endl;
	}
}
