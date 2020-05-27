#include <bits/stdc++.h>
using namespace std;

void greedy(string s, int k) {
	int n = 0, x[256] = {};
	long long res = 0;
	for(int i = 0; i < s.size(); i++) {
		if(x[s[i]] == 0)
			n++;
		x[s[i]]++;
	}
	sort(x, x+256, greater<int>());
	int i = 0;
	while(k > 0 && x[i] != 0) {
		int t = x[0]-1;
		while(x[i] > t && k > 0) {
			x[i] = t;
			k--;
			i++;
		}
		i = 0;
	}
	for(int i = 0; i < n - k; i++)
		res += (long long) x[i] * x[i];
	cout << res <<endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int k;	string s;
		cin >> k >> s;
		greedy(s, k);
	}
}
