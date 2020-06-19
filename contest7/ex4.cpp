#include <bits/stdc++.h>
using namespace std;
stack<char> st;

bool check(string s) {
	while(!st.empty())
		st.pop();
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '{' || s[i] == '[' || s[i] == '(')
			st.push(s[i]);
		else {
			if(st.empty())
				return false;
			if(s[i] == ')' && st.top() == '(')
				st.pop();
			else if(s[i] == ']' && st.top() == '[')
				st.pop();
			else if(s[i] == '}' && st.top() == '{')
				st.pop();
			else return false;
		}
	}
	if(st.size() == 0)
		return true;
	return false;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s; cin >> s;
		if(check(s))
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
