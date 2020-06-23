#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
	queue<int> a; a.push(n);
	queue<int> c; c.push(0);
	set<int> s; s.insert(n);
	while(a.size() > 0) {
		int f = a.front(); a.pop();
		int d = c.front(); c.pop();
		if(f == 1) return d;
		if(f-1 == 1) return d+1;
		else if(s.find(f - 1) == s.end()){
			a.push(f - 1);
			c.push(d + 1);
			s.insert(f - 1);
		}
		for(int i = 2; i*i <= f; i++) {
			if(f%i == 0 && s.find(f / i) == s.end()) {
				a.push(f / i);
				c.push(d + 1);
				s.insert(f / i);
			}
		}
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		cout << solve(n) << endl;
	}
}
