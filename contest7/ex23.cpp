#include <bits/stdc++.h>
using namespace std;

string toString(stack<char> s) {
	string res = "";
	while(!s.empty()) {
		res = s.top() + res;
		s.pop();
	}
	return res;
}

string solve(string str) {
	int length = str.size();
	stack<char> s;
	stack<int> o;
	for(int i = 0; i < length; i++) {
		if(str[i] == '[') {
			s.push('[');
			if(i == 0 || !isdigit(str[i-1]))
				o.push(1);
		}
		else if(str[i] == ']') {
			string temp = "";
			int t = 1;
			while(s.top() != '[') {
				temp = s.top() + temp;
				s.pop();
			} s.pop();
			if(!o.empty()) {
				t = o.top();
				o.pop();
			}
			for(int i = 0; i < t; i++)
				for(int j = 0; j < temp.size(); j++)
					s.push(temp[j]);
		} else if(isdigit(str[i])) {
			int t = 0;
			while(isdigit(str[i]))
				t = t * 10 + str[i++] - '0';
			i = i - 1;
			o.push(t);
		} else s.push(str[i]);
	}
	return toString(s);
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string str; cin >> str;
		cout << solve(str) << endl;
	}
}
