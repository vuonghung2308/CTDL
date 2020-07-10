#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int L = INT_MAX, R = INT_MIN, S = 0, temp;
		bool a[100001] = {}; // danh dau phan tu da co
		for(int i = 0; i < n; i++) {
			cin >> temp;
			if(!a[temp]) {
				a[temp] = true;
				L = min(temp, L);
				R = max(temp, R);
				S = S + 1;
			}
		}
		cout << R - L + 1 - S << endl;
	}
}
