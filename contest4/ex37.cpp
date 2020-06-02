#include <bits/stdc++.h>
using namespace std;

int Find(long long *a, long long x, int l ,int r) {
	if(l > r) return -1;
	if(l == r && a[l] <= x) return l+1;
	int mid = (l+r) / 2;
	if(a[mid] == x) return mid+1;
	if(a[mid] < x && a[mid+1] > x) return mid+1;
	if(a[mid] > x) return Find(a, x, l, mid-1);
	return Find(a, x, mid+1, r);
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; long long k; cin >> n >> k;
		long long *a = new long long[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << Find(a, k, 0, n-1) << endl;
	}
}
