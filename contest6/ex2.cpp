#include <bits/stdc++.h>
using namespace std;

bool compare(int *a, int *b) {
	if(a[1] == b[1]) return a[2] < b[2];
	return a[1] < b[1];
}

void show(int **a, int n) {
	sort(a, a+n, compare);
	for(int i = 0; i < n; i++) 
		cout << a[i][0] << ' ';
	cout << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, x; cin >> n >> x;
		int **a = new int*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[3];
			cin >> a[i][0];
			a[i][1] = abs(a[i][0]-x);
			a[i][2] = i;
		}
		show(a, n);
	}
}
