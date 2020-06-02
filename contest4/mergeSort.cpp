#include <iostream>
using namespace std;

void merge(int *a, int l, int m, int r) {
	int nL = m-l+1, nR = r-m;
	int *L = new int[nL];
	int *R = new int[nR];
	int i = 0, j = 0, k = l;
	for(int i = 0; i < nL; i++)
		L[i] = a[i+l];
	for(int i = 0; i < nR; i++)
		R[i] = a[m+i+1];
	while(i < nL && j < nR) {
		if(L[i] < R[j]) a[k++] = L[i++];
		else a[k++] = R[j++];
	}
	
	while(i < nL) a[k++] = L[i++];
	while(j < nR) a[k++] = R[j++];
}

void mergeSort(int *a, int l, int r) {
	if(l < r) {
		int m = (l+r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
}

int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	mergeSort(a, 0, n-1);
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
}
