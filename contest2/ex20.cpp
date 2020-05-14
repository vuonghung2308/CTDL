#include <bits/stdc++.h>
using namespace std;

void show(int **res, int n) {
	for(int x = 0; x < n; x++) {
		cout << '[';
		for(int y = 0; y < x; y++)
			cout << res[x][y] << ' ';
		cout << res[x][x] << ']' << ' ';
	}
	cout << endl;
}

void addResult(int *a, int n, int **res) {
	for(int i = 0; i <= n-1; i++)
		res[n-1][i] = a[i];
}

void Try(int *a, int n, int **res) {
	addResult(a, n, res);
	if(n == 1) {
		return;
	} else {
		for(int i = 0; i < n-1; i++)
			a[i] += a[i+1];
		Try(a, n-1, res);
	}
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {	
		int n; cin >> n;
		int a[n];
		int **res = new int*[n];
		for(int x = 0; x < n; x++) {
			cin >> a[x];
			res[x] = new int[x+1];
		}
		Try(a, n, res);
		show(res, n);
	}
}

