#include <bits/stdc++.h>
using namespace std;

bool isOk(string s) {
	if(s == "")
		return false;
	int x = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '(') x++;
		else if(s[i] == ')') x--;
		if(x < 0) return false;
	}
	return x == 0;
}

void remove(string s, bool &has) {
	queue<string> q;
	set<string> visit;
	visit.insert(s);
	q.push(s);
	bool level = false;
	while(!q.empty()) {
		string str = q.front();
		q.pop();
		if(isOk(str)) {
			has = true;
			cout << str << ' ';
			level = true;
		}
		if(level) continue;
		for(int i = 0; i < str.length(); i++) {
			if(str[i] == '(' || str[i] == ')') {
				string temp = str.substr(0, i) + str.substr(i+1);
				if(visit.find(temp) == visit.end()) {
					q.push(temp);
					visit.insert(temp);
				}
			}
		}
	}
	
}

int main() {
	int t; cin >> t; 
	for(int i = 0; i < t; i++) {
		string s; cin >> s;
		bool has = false;
		remove(s, has);
		if(!has) cout << "-1";
		cout << endl;
	}
}
