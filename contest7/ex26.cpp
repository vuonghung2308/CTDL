#include <bits/stdc++.h>
using namespace std;

void solve(int *a, int n) {
	int res[n] = {1};
	stack<int> s;
	s.push(-1); s.push(0);
	for(int i = 1; i < n; i++) {
		while(s.top() != -1 && a[s.top()] <= a[i])
			s.pop();
		res[i] = i - s.top();
		s.push(i);
	}
	for(int i = 0; i < n; i++)
		cout << res[i] << ' ';
}

int main() {
	int n; cin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	solve(a, n);
}
