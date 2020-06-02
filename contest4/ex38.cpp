#include <iostream>
using namespace std;

int merge(int *L, int *R, int nl, int nr, int n) {
	int *res = new int[nl+nr];
	int i = 0, j = 0, k = 0;
	while(i < nl && j < nr && k < n) {
		if(L[i] < R[j]) res[k++] = L[i++];
		else res[k++] = R[j++];
	}
	if(k < n) {
		while(i < nl && k < n) res[k++] = L[i++];
		while(j < nr && k < n) res[k++] = R[j++];
	}
	return res[n-1];
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int nl, nr, n; cin >> nl >> nr >> n;
		int *L = new int[nl];
		int *R = new int[nr];
		for(int i = 0; i < nl; i++)
			cin >> L[i];
		for(int i = 0; i < nr; i++)
			cin >> R[i];
		cout << merge(L, R, nl, nr, n) << endl;
	}
}
