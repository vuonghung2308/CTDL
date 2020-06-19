#include <bits/stdc++.h>
using namespace std;

void print(stack<char> c) {
	string s = "";
	while(!c.empty()) {
		s.insert(s.begin(), c.top());
		c.pop();
	}
	cout << s << endl;
}

void solve(string str) {
	stack<char> c, s;
	stack<char> temp;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] != ')') {
			if(str[i] == '(' && !c.empty())
				s.push(c.top());
			c.push(str[i]);
		} else {
			while(c.top() != '(') {
				if(c.top() != '+' && c.top() != '-')
					temp.push(c.top());
				else {
					if(s.empty() || s.top() == '+' || s.top() == '(')
						temp.push(c.top());
					else {
						if(c.top() == '-')
							temp.push('+');
						else temp.push('-');
					}
				}
				c.pop();
			}
			c.pop(); s.pop();
			if(temp.top() == '+' || temp.top() == '-')
				c.pop();
			while(!temp.empty()) {
				c.push(temp.top());
				temp.pop();
			}
		}
	}
	print(c);
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string str; cin >> str;
		solve(str);
	}
}
