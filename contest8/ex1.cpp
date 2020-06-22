#include <bits/stdc++.h>
using namespace std;

void solve(queue<int> &q, int key, int value = 0) {
	switch(key) {
		case 1: {
			cout << q.size() << endl;
			break;
		}
		case 2: {
			if(q.empty()) cout << "YES" << endl;
			else cout << "NO" << endl;
			break;
		}
		case 3: {
			q.push(value);
			break;
		}
		case 4: {
			if(!q.empty()) q.pop();
			break;
		}
		case 5: {
			if(!q.empty()) cout << q.front() << endl;
			else cout << -1 << endl;
			break;
		}
		case 6: {
			if(!q.empty()) cout << q.back() << endl;
			else cout << -1 << endl;
			break;
		}
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		queue<int> q;
		for(int i = 0; i < n; i++) {
			int key, value = 0; cin >> key;
			if(key == 3) cin >> value;
			solve(q, key, value);
		}
	}
}
