#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
	return (a > b)?a:b;
}

int max(int a, int b, int c) {
	return max(a, max(b, c));
}

int findMax_(int *a, int l, int m ,int r) {
	int maxL = INT_MIN, maxR = INT_MIN, sum = 0;
	for(int i = m; i >= l; i--) {
		sum = sum + a[i];
		if(sum > maxL)
			maxL = sum;
	} sum = 0;
	for(int i = m+1; i <= r; i++) {
		sum = sum + a[i];
		if(sum > maxR)
			maxR = sum;
	}
	return max(maxL, maxR, maxR + maxL);
}

int findMax(int *a, int l, int r) {
	if(l == r) return a[r];
	int m = (l+r) /2;
	int mL = findMax(a, l, m);
	int mR = findMax(a, m+1, r);
	int mM = findMax_(a, l, m, r);
	return max(mL, mR, mM);
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << findMax(a, 0, n-1) << endl;
	}
}
