#include <bits/stdc++.h>
using namespace std;

void greedy(int n) {
	int x = n / 7;
	int n7 = 0, n4 = 0;
	int l = INT_MAX;
	for(int i = 0; i <= x; i++) {
		int j = (n - i*7) / 4;
		if(i*7 + j*4 == n && i + j < l) {
			n7 = i;
			n4 = j;
			l = n7 + n4;
		}
	}
	string res(n4, '4');
	string res_(n7, '7');
	if(res + res_ == "") cout << "-1" << endl;
	else cout << res + res_ << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		greedy(n);
	}
}
