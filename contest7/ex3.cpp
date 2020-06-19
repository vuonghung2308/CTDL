#include <bits/stdc++.h>
using namespace std;

string reverse(string s) {
	string res = "";
	stack<int> t;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == ' ') {
			while(!t.empty()) {
				res.push_back(t.top());
				t.pop();
			}
			res.push_back(s[i]);
		} else t.push(s[i]);
	}
	while(!t.empty()) {
		res.push_back(t.top());
		t.pop();
	}
	return res;
}

int main() {
	int n; cin >> n;
	cin.ignore();
	while(n) {
		string s; getline(cin, s);
		if(s != "") {
			cout << reverse(s) << endl;
			n--;
		}
	}
}
