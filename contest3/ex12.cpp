#include <bits/stdc++.h>
using namespace std;

bool greedy(string s) {
	int a[256] = {};
	for(int i = 0; i < s.length(); i++)
		a[s[i]]++;
	sort(a, a+256, greater<int>());
	int i = 0, x = 0;
	while(a[i] != 0) {
		x = abs(x - a[i]);
		if(x <= 1) return true;
		i++;
	}
	return x <= 1;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s; cin >> s;
		if(greedy(s)) cout << 1 << endl;
		else cout << -1 << endl;
	}
}
