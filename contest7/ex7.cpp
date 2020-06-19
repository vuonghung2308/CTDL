#include <bits/stdc++.h>
using namespace std;

int solve(string str) {
	stack<int> s;
	int count = 0;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] == '(')
			s.push('(');
		else {
			if(s.empty()) {
				count = count + 1;
				s.push('(');
			} else s.pop();
		}
	}
	count = count + s.size() / 2;
	return count;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string str; cin >> str;
		cout << solve(str) << endl;
	}
}
