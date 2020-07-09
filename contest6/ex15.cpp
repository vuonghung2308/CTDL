#include <bits/stdc++.h>
using namespace std;

void merge(int *a, int l, int m, int r) {
	int nl = m-l+1; int L[nl];
	int nr = r-m; int R[nr];
	for(int i = 0; i < nl; i++)
		L[i] = a[l+i];
	for(int i = 0; i < nr; i++)
		R[i] = a[m+1+i];
	int i = 0, j = 0, na = l;
	while(i < nl && j < nr) {
		if(L[i] < R[j]) {
			a[na++] = L[i++];
		} else a[na++] = R[j++];
	}
	while(i < nl)
		a[na++] = L[i++];
	while(j < nr)
		a[na++] = R[j++];
}

void mergeSort(int *a, int l, int r) {
	if(l < r) {
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		mergeSort(a, 0, n-1);
		for(int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << endl;
	}
}
