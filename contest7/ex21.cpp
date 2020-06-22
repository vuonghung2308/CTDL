#include <bits/stdc++.h>
using namespace std;

void solve(int *a, int n) {
	int res1[n] = {}; res1[n-1] = -1;
	int res[n] = {}; res[n-1] = -1;
	stack<int> s1; s1.push(n-1);
	stack<int> s; s.push(n-1);
	
	for(int i = n-2; i >= 0; i--) {
		
		while(!s1.empty() && s1.top() != -1 && a[i] <= a[s1.top()])
			s1.pop();
		if(s1.empty()) res1[i] = -1;
		else res1[i] = s1.top();
		s1.push(i);
		
		while(!s.empty() && s.top() != -1 && a[i] >= a[s.top()])
			s.pop();
		if(s.empty()) res[i] = -1;
		else res[i] = s.top();
		s.push(i);
		
	}
	for(int i = 0; i < n; i++)
		if(res[i] != -1 && res1[res[i]] != -1)
			cout << a[res1[res[i]]] << ' ';
		else cout << -1 << ' ';
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
