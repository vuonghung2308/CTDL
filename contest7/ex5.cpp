#include <bits/stdc++.h>
using namespace std;

int count(string s) {
	stack<int> st;
	int m = 0;
	st.push(-1);
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(')
			st.push(i);
		else {
			st.pop();
			if(!st.empty()) m = max(m, i - st.top());
			else st.push(i);
		}
	}
	return m;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s; cin >> s;
		cout << count(s) << endl;
	}
}
