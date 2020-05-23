#include <bits/stdc++.h>
using namespace std;

bool greedy(string s, int d) {
	int c[256] = {};
	int n = s.size();
	for(int i = 0; i < s.size(); i++)
		c[s[i]]++;
	int res[n] = {};
	sort(c, c+256, greater<int>());
	int i = 0, x = 0;
	while(c[i]!=0) cout << c[i++] << ' ';
	cout << endl;
	i = 0;
	while(c[i] != 0) {
		cout << (x + (c[i]-1)*d) << ' ' << n-1 << endl;
		if((x + (c[i]-1)*d) <= n-1) {
			cout << 'A' << endl;
			for(int j = 0; j < c[i]; i++)
				res[x+d*j] = 1;
			while(res[x] == 1) x++;
		} else {
			cout << i << ' ' << c[i] << ' ' << x << endl;
			return false;
		}
		i++;
		cout << c[i] << endl;
	}
	if(x == n) return true;
	else {
		cout << x << ' '  << 1 << endl;
		return false;
	}
}

int main() {
	int k;
	string s; cin >> k >> s;
	cout << greedy(s, k) << endl;
}
