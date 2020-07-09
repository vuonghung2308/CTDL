#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, i, j; cin >> n;
		int a[n], b[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(a, a+n);
		i = 0; j = n - 1;
		while(i < n && a[i] == b[i])
			i = i + 1;
		while(j >= 0 && a[j] == b[j])
			j = j - 1;
		cout << i+1 << ' ' << j+1 << endl;
	}
}
