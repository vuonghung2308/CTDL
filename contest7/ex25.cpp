#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m) {
	vector<int> a;
	int x = 0;
	for(int i = 0; i < n; i++)
		a.push_back(i+1);
	while(a.size() != 1) {
		if(x+m < a.size()) {
			a.erase(a.begin()+x+m);
			if(x+m < a.size()) x = x+m;
			else x = 0;
		} else {
			int t = m - a.size() + x;
			
			x = t % a.size();			
			a.erase(a.begin() + x);
			if(x == a.size())
				x = 0;
		}
	}
	return a[0];
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, m; cin >> n >> m;
		cout << solve(n, m) << endl;
	}
}
