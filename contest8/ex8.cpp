#include <bits/stdc++.h>
using namespace std;

bool check(string s, int n) {
	long long t = 0;
	for(int i = 0; i < s.size(); i++)
		t = t * 10 + s[i] - '0';
	return t % n == 0;
}

string solve(int n) {
	string s = "1";
	queue<string> q;
	q.push(s);
	while(!check(q.front(), n)) {
		s = q.front(); q.pop();
		string s1 = s + '0';
		string s2 = s + '1';
		q.push(s1); q.push(s2);		
	}
	return q.front();
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		cout << solve(n) << endl;
	}
}
