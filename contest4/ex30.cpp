#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000000+7;

void mul(long long **a, long long **b, int n) {
	long long **t = new long long*[n];
	for(int i = 0; i < n; i++) {
		t[i] = new long long[n];
		for(int j = 0; j < n; j++) {
			long long temp = 0;
			for(int x = 0; x < n; x++) {
				temp += (a[i][x] * b[x][j])%mod;
				temp = temp%mod;
			}
			t[i][j] = temp;
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = t[i][j];
}

void pow(long long **a, int n, int k) {
	if(k == 1)
		return;
	if(k%2 == 1) {
		long long **H = new long long*[n];
		for(int i = 0; i < n; i++) {
			H[i] = new long long[n];
			for(int j = 0; j < n; j++)
				H[i][j] = a[i][j];
		}
		pow(a, n, k/2);
		mul(a, a, n);
		mul(a, H, n);
	} else {
		pow(a, n, k/2);
		mul(a, a, n);
	}
}

int main() {
	long long **a = new long long*[2];
	a[0] = new long long[2];
	a[1] = new long long[2];
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		a[0][0] = 1;
		a[0][1] = 1;
		a[1][0] = 1;
		a[1][1] = 0;
		pow(a, 2, n);
		cout << a[0][1] << endl;
	}
}
