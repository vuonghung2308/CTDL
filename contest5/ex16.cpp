#include <iostream>
using namespace std;

int solve(int *a, int n) {
	int s[n] = {};
	int m = 0;
	for(int i = 0; i < n; i++) {
		s[i] = a[i];
		for(int j = 0; j < i; j++)
			if(a[i] > a[j])
				s[i] = max(s[i], s[j]+a[i]);
		if(m < s[i])
			m = s[i];
	}
	return m;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << solve(a, n) << endl;
	}
}
