#include <iostream>
using namespace std;

int solve(string s) {
	int n = s.size(), l = 0;
	int a[n+1][n+1] = {};
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(s[i-1] == s[j-1] && j != i) 
				a[i][j] = a[i-1][j-1] + 1;
			else a[i][j] = max(a[i-1][j], a[i][j-1]);
		}
	}
	
	return a[n][n];
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int k;
		string s; cin >> k >> s;
		cout << solve(s) << endl;
	}
}
