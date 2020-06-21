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

long long calculate1(long long op1, long long op2, char c) {
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

int sign(char c) {
	switch(c) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
	return -1;
}

long long calculate(string str) {
	stack<long long> v;
	stack<char> o;
	int length = str.length();
	for(int i = 0; i < length; i++) {
		if(str[i] == ' ')
			continue;
		if(isOperator(str[i])) {
			while(!o.empty() && sign(str[i]) <= sign(o.top())) {
				long long op2 = v.top(); v.pop();
				long long op1 = v.top(); v.pop();
				char c = o.top(); o.pop();
				v.push(calculate1(op1, op2, c));
			}
			o.push(str[i]);
		} else if(str[i] == ')') {
			while(o.top() != '(') {
				long long op2 = v.top(); v.pop();
				long long op1 = v.top(); v.pop();
				char c = o.top(); o.pop();
				v.push(calculate1(op1, op2, c));
			}
			o.pop();
			
		} else if(str[i] == '(') {
			o.push('(');
		}
		else {
			long long value = 0;
			while(isdigit(str[i]) && i < length) {
				value = value * 10 + str[i] - '0';
				i = i + 1;
			}
			i = i - 1;
			v.push(value);
		}
	}
	while(!o.empty()) {
		long long op2 = v.top(); v.pop();
		long long op1 = v.top(); v.pop();
		char c = o.top(); o.pop();
		v.push(calculate1(op1, op2, c));
	}
	return v.top();	
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string str; cin >> str;
		cout << calculate(str) << endl;
	}
}
