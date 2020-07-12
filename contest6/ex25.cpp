#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	for(int z = 0; z < t; z++) {
		int n, m1, m2; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);
		m1 = m2 = a[0];
		for(int i = 0; i < n; i++) {
			if(a[i] != m1) {
				m2 = a[i];
				break;
			}
		}
		if(m1 != m2)
			cout << m1 << ' ' << m2 << endl;
		else cout << -1 << endl;
	}
}
