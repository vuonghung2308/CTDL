#include <bits/stdc++.h>
using namespace std;

int* mul(int *a, int *b, int n, int m) {
	int *res = new int[n+m-1];
	for(int i = 0; i <n+m-1; i++)
		res[i] = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			res[i+j] = res[i+j] + a[i]*b[j];
	}
	return res;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, m; cin >> n >> m;
		int *a = new int[n];
		int *b = new int[m];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < m; i++)
			cin >> b[i];
		int *res = mul(a, b, n, m);
		for(int i = 0; i < n+m-1; i++)
			cout << res[i] << ' ';
		cout << endl;	
	}
}
