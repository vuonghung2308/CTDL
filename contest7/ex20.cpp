#include <bits/stdc++.h>
using namespace std;

void solve(int *a, int n) {
	int res[n] = {};
	res[n-1] = -1;
	stack<int> s; s.push(a[n-1]);
	for(int i = n-2; i >= 0; i--) {
		while(!s.empty() && a[i] >= s.top())
			s.pop();
		if(s.empty()) res[i] = -1;
		else res[i] = s.top();
		s.push(a[i]);
	}
	for(int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << endl;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		solve(a, n);
	}
}
