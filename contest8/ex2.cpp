#include <bits/stdc++.h>
using namespace std;

void solve(queue<int> &q, string key, int value = 0) {
	if(key == "PUSH") {
		q.push(value);
	}
	else if(key == "POP") {
		if(!q.empty()) q.pop();
	}
	else if(key == "PRINTFRONT") {
		if(!q.empty()) cout << q.front() << endl;
		else cout << "NONE" << endl;
	}
}

int main() {
	int n; cin >> n;
	queue<int> q;
	for(int i = 0; i < n; i++) {
		string key;int value = 0; cin >> key;
		if(key == "PUSH") cin >> value;
		solve(q, key, value);
	}
}
