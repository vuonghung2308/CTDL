#include <bits/stdc++.h>
using namespace std;

bool greedy(string s, int d) {
	int n = s.size();
	int c[256] = {}, res[n] = {};
	for(int i = 0; i < s.size(); i++)
		c[s[i]]++;
	sort(c, c+256, greater<int>());
	int i = 0, x = 0;
	while(c[i] != 0) {
		for(int j = 0; j < c[i]; j++)
			if(x+d*j < n)
				res[x+d*j] = c[i];
			else return false;
		while(res[x] != 0 && x < n) x++;
		i++;
	}
	if(x == n) return true;
	else return false;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int k;
		string s; cin >> k >> s;
		if(greedy(s, k)) cout << 1 << endl;
		else cout << -1 << endl;
	}
}
