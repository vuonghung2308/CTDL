#include <bits/stdc++.h>
using namespace std;

void show(int *a, int n) {
	sort(a, a+n, greater<int>());
	for(int i = 0; i < n/2; i++) 
		cout << a[i] << ' ' << a[n-i-1] << ' ';
	if(n%2 != 0)
		cout << a[n/2] << endl;
	else cout << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		show(a, n);
	}
}
