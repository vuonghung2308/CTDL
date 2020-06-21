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

int calculate(int op1, int op2, char c) {
	switch(c) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
	}
}

int convert(string str) {
	stack<int> s;
	int length = str.size();
	for(int i = length-1; i >= 0; i--) {
		if(isOperator(str[i])) {
			int op1 = s.top(); s.pop();
			int op2 = s.top(); s.pop();
			s.push(calculate(op1, op2, str[i]));
		} else s.push(str[i] - '0');
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
