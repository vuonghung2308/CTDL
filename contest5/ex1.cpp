#include <iostream>
using namespace std;

int solve(string s1, string s2) {
	int n1 = s1.size(), n2 = s2.size();
	int d[n2+1][n1+1] = {};
	for(int i = 1; i <= n2; i++) {
		for(int j = 1; j <= n1; j++) {
			if(s2[i-1] == s1[j-1])
				d[i][j] = 1 + d[i-1][j-1];
			else 
				d[i][j] = max(d[i-1][j], d[i][j-1]);
		}
	}
	return d[n2][n1];
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		cout << solve(s1, s2) << endl;
	}
}
