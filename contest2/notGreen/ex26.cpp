#include <bits/stdc++.h>
using namespace std;

void swap(char &a, char &b) {
	char t = a;
	a = b;
	b = t;
}

void Try(int i, int n, string s, string &res) {
	for(int j = s.size()-1; j > i; j--) {
		if(i < n) {
			swap(s[i], s[j]);
			res = (res < s)?s:res;
			if(i < n && s >= res) Try(i+1, n, s, res);
			swap(s[i], s[j]);
		}
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n;
		string s, res; cin >> n >> s;
		res = s;
		Try(0, n, s, res);
		cout << res << endl;
	}
}
