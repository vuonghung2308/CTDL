#include <bits/stdc++.h>
using namespace std;

void show(int *a, int n) {
	cout << '[';
	for(int i = 0; i < n-1; i++)
		cout << a[i] << ' ';
	cout << a[n-1] << ']' << endl;
}

void Try(int *a, int n) {
	show(a, n);
	if(n == 1) {
		return;
	} else {
		for(int i = 0; i < n-1; i++)
			a[i] += a[i+1];
		Try(a, n-1);
	}
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {	
		int n; cin >> n;
		int a[n];
		for(int x = 0; x < n; x++)
			cin >> a[x];
		Try(a, n);
	}
}
