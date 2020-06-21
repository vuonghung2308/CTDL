#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
	switch(c) {
		case '+':
		case '-':
		case '*':
		case '/':
			return true;
	}
	return false;
}

string convert(string str) {
	stack<string> s;
	int length = str.size();
	for(int i = 0; i < length; i++) {
		if(isOperator(str[i])) {
			string op2 = s.top(); s.pop();
			string op1 = s.top(); s.pop();
			string temp = str[i] + op1 + op2;
			s.push(temp);
		} else s.push(string (1, str[i]));
	}
	return s.top();
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string str; cin >> str;
		cout << convert(str) << endl;
	}
}
