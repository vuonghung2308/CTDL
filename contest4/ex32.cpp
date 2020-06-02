#include <bits/stdc++.h>
using namespace std;

long long merge(long long *a, int l, int m, int r) {
	int i = 0, j = 0, k = l;
	long long count = 0;
	int nL = m-l+1, nR = r-m;
	int *L = new int[nL];
	int *R = new int[nR];
	for(int i = 0; i < nL; i++)
		L[i] = a[i+l];
	for(int i = 0; i < nR; i++)
		R[i] = a[m+i+1];
	
	while(i < nL && j < nR) {
		if(L[i] <= R[j]) a[k++] = L[i++];
		else {
			a[k++] = R[j++];
			count += (long long) nL - i;
		}
	}
	
	while(i < nL) a[k++] = L[i++];
	while(j < nR) a[k++] = R[j++];
	return count;
}

long long mergeSort(long long *a, int l, int r) {
	long long count = 0;
	if(l < r) {
		int m = (l+r) / 2;
		count += mergeSort(a, l, m);
		count += mergeSort(a, m+1, r);
		count += merge(a, l, m, r);
	}
	return count;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		long long *a = new long long[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << mergeSort(a, 0, n-1) << endl;
	}
}
