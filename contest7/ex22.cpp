#include <bits/stdc++.h>
using namespace std;

long long solve(int *a, int n) {
	int l[n] = {}; l[n-1] = n-1;
	int r[n] = {}; r[0] = 0;
	stack<int> s; s.push(n-1);
	stack<int> s1; s1.push(0);
	long long m = 0;
	
	for(int i = n-2; i >= 0; i--) {
		l[i] = i;
		while(!s.empty() && a[s.top()] >= a[i]) {
			l[i] = l[s.top()];
			s.pop();
		}
		s.push(i);
	}
	
	for(int i = 0; i < n; i++) {
		r[i] = i;
		while(!s1.empty() && a[s1.top()] >= a[i]) {
			r[i] = r[s1.top()];
			s1.pop();
		}
		s1.push(i);
	}
	
	for(int i = 0; i < n; i++) {
		long long t = (long long) a[i] * (abs(i-l[i]) + abs(i-r[i]) + 1);
		m = max(m, t);
	}
	return m;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << solve(a, n) << endl;
	}
}
