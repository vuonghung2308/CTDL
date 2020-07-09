#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, x; cin >> n >> x;
		int a[n] = {};
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int count = upper_bound(a, a+n, x) - lower_bound(a, a+n, x);
		count = (count > 0)?count:-1;
		cout << count << endl;
	}
}
