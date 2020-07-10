#include <bits/stdc++.h>
using namespace std;

int partition(int *a, int l, int r) {
	int pivot = a[r];
	int i = l - 1;
	for(int j = l; j < r; j++) {
		if(a[j] < pivot) {
			i = i + 1;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[r]);
	return i+1;
}

void quickSort(int *a, int l, int r) {
	if(l < r) {
		int pi = partition(a, l, r);
		quickSort(a, l, pi-1);
		quickSort(a, pi+1, r);
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		quickSort(a, 0, n-1);
		for(int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << endl;
	}
}
