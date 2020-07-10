#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, m; cin >> n >> m;
		long long max = INT_MIN, min = INT_MAX, e;
		for(int i = 0; i < n; i++) {
			cin >> e;
			max = (e > max)?e:max;
		}
		for(int i = 0; i < m; i++) {
			cin >> e;
			min = (e < min)?e:min;
		}
		cout << max*min << endl;
	}
}
