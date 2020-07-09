#include <bits/stdc++.h>
using namespace std;

void add(string s, bool *has) {
	int length = s.length();
	for(int i = 0; i < length; i++)
		has[s[i] - '0'] = true;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		bool has[10] = {};
		for(int i = 0; i < n; i++) {
			string s; cin >> s;
			add(s, has);
		}
		for(int i = 0; i < 10; i++)
			if(has[i])
				cout << i << ' ';
		cout << endl;
	}
}
