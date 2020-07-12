#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *a, int x, int l, int r) {
	if(l > r)
		return -1;
	int m = (l+r) / 2;
	if(a[m] == x)
		return m+1;
	if(a[m] < x)
		return binarySearch(a, x, m+1, r);
	return binarySearch(a, x, l, m-1);
}

int findPivot(int *a, int l, int r) {
	if(l > r)
		return -1;
	if(l == r)
		return l;
	int m = (l+r) / 2;
	if(a[m] > a[m+1])
		return m;
	if(a[m-1] > a[m])
		return m-1;
	if(a[l] < a[m])
		return findPivot(a, m+1, r);
	return findPivot(a, l, m-1);
}

int findX(int *a, int x, int l, int r) {
	int pivot = findPivot(a, 0, r);
	if(pivot == -1) 
		return binarySearch(a, x, l, r);
	if(a[pivot] == x)
		return pivot;
	if(a[0] > x)
		return binarySearch(a, x, pivot+1, r);
	return binarySearch(a, x, l, pivot-1);
}

int main() {
	int t; cin >> t;
	for(int z = 0; z < t; z++) {
		int n, x; cin >> n >> x;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << findX(a, x, 0, n-1) << endl;
	}
}
