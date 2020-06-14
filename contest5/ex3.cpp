#include <iostream>
using namespace std;

bool has(int *a, int n, int s) {
	int x[s+1][n+1] = {};
	for(int i = 1; i <= s; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == a[j-1] || x[i][j-1] == i) x[i][j] = i;
			else if(i < a[j-1]) x[i][j] = x[i][j-1];
			else {
				int t = i - a[j-1];
				x[i][j] = x[t][j-1] + a[j-1];
			}
		}
	}
	return s == x[s][n];
}

int main() {
	int t; cin >> t;
		for(int x = 0; x < t; x++) {
		int n, s; cin >> n >> s;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		if(has(a, n, s)) cout << "YES\n";
		else cout << "NO\n";
	}
}
