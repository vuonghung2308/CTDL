#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *a, int x, int l, int r) {
	if(l > r)
		return -1;
	int m = (l+r) / 2;
	if(a[m] == x)
		return 1;
	if(a[m] < x)
		return binarySearch(a, x, m+1, r);
	return binarySearch(a, x, l, m-1);
}

int main() {
	int t; cin >> t;
	for(int z = 0; z < t; z++) {
		int n, x; cin >> n >> x;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << binarySearch(a, x, 0, n-1) << endl;
	}
}
