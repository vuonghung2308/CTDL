#include <bits/stdc++.h>
using namespace std;

void greedy(long long p, long long q) {
	while(q%p != 0) {
		long long x = q/p + 1;
		p = x*p-q;
		q = x*q;
		cout << "1/" << x << " + ";
	}
	cout << "1/" << q/p << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		long long p, q;
		cin >> p >> q;
		greedy(p, q);
	}
}
