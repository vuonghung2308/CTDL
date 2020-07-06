#include <bits/stdc++.h>
using namespace std;

int findMin(int *a, int x, int n) {
	int min = x;
	for(int i = x; i < n; i++)
		if(a[i] < a[min])
			min = i;
	return min;
}

int count(int *a, int n) {
	int res = 0;
	for(int i = 0; i < n; i++) {
		int x = findMin(a, i, n);
		if(i != x) {
			res = res + 1;
			swap(a[i], a[x]);
		}
	}
	return res;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << count(a, n) << endl;
	}
}
