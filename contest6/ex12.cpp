#include <bits/stdc++.h>
using namespace std;

void print(int *a, int k) {
	for(int i = 0; i < k; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, k; cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n, greater<int>());
		print(a, k);
	}
}
