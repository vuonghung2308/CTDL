#include <bits/stdc++.h>
using namespace std;

int solve(string n) {
	int res = 0, t = 0;
	bool isOk = false;
	for(int i = 0; i < n.size(); i++) {
		if(isOk || n[i] == '1')
			t = 1;
		else if(n[i] > '1') {
			t = 1;
			isOk = true;
		} else t = 0;
		res = res * 2 + t;
	}
	return res;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string n; cin >> n;
		cout << solve(n) << endl;
	}
}
