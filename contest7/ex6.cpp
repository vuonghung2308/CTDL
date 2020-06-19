#include <bits/stdc++.h>
using namespace std;

bool solve(string a) {
	stack<char> s;
	for(int i = 0; i < a.size(); i++) {
		if(a[i] != ')')
			s.push(a[i]);
		else {
			bool has = false;
			while(s.top() != '(') {
				if(s.top() == '*' || s.top() == '+' || s.top() == '-' || s.top() == '/')
					has = true;
				s.pop();
			}
			s.pop();
			if(!has) return true;
		}
	}
	return false;
}

int main() {
	int t; cin >> t;
	cin.ignore();
	for(int i = 0; i < t; i++) {
		string a = ""; 
		while(a == "")
			getline(cin, a);
		if(solve(a)) cout << "Yes\n";
		else cout << "No\n";
	}
}
