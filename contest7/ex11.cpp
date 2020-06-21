#include <bits/stdc++.h>
using namespace std;

int sign(char c) {
	if(c == '^') return 3;
	if(c == '*' || c == '/') return 2;
	if(c == '+' || c == '-') return 1;
	return -1;
}

string convert(string str) {
	stack<char> s;
	string res = "";
	
	for(int i = 0; i < str.size(); i++) {
		if(str[i] == ')') {
			while(s.top() != '(') {
				res = res + s.top();
				s.pop();
			}
			s.pop();
		} else if(str[i] == '(') {
			s.push('(');
		} else if(str[i] == '+' || str[i] == '-' || str[i] == '^'
				|| str[i] == '*' || str[i] == '/') {
			while(!s.empty() && sign(str[i]) <= sign(s.top())) {
				res = res + s.top();
				s.pop();
			}
			s.push(str[i]);
		} else res = res + str[i];
	}
	while(!s.empty()) {
		if(s.top()!='(')
			res = res + s.top();
		s.pop();
	}
	return res;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string str; cin >> str;
		cout << convert(str) << endl;
	}
}
