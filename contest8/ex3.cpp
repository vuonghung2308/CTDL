#include <bits/stdc++.h>
using namespace std;

void solve(deque<int> &q, string key, int value = 0) {
	if(key == "PUSHFRONT") {
		q.push_front(value);
	} else if(key == "PUSHBACK") {
		q.push_back(value);
	} else if(key == "POPFRONT") {
		if(!q.empty()) q.pop_front();
	} else if(key == "POPBACK") {
		if(!q.empty()) q.pop_back();
	} else if(key == "PRINTFRONT") {
		if(!q.empty()) cout << q.front() << endl;
		else cout << "NONE" << endl;
	} else if(key == "PRINTBACK") {
		if(!q.empty()) cout << q.back() << endl;
		else cout << "NONE" << endl;
	}
}

int main() {
	int n; cin >> n;
	deque<int> q;
	for(int i = 0; i < n; i++) {
		string key;int value = 0; cin >> key;
		if(key == "PUSHFRONT" || key == "PUSHBACK")
			cin >> value;
		solve(q, key, value);
	}
}
