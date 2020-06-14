#include <iostream>
using namespace std;

int solve(int m, int n, int **a) {
	int s[m][n] = {}, res = 0;
	for(int i = 0; i < n; i++) {
		s[0][i] = a[0][i];
		if(s[0][i] > res)
			res = s[0][i];
	}
	
	for(int i = 0; i < m; i++) {
		s[i][0] = a[i][0];
		if(s[0][i] > res)
			res = s[0][i];
	}
	
	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			if(a[i][j]!=0)
				s[i][j] = min(min(s[i-1][j], s[i][j-1]), s[i-1][j-1]) + 1;
			else s[i][j] = 0;
			if(s[i][j] > res)
				res = s[i][j];
		}
	}
	return res;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int m, n;
		cin >> m >> n;
		int **a = new int*[m];
		for(int i = 0; i < m; i++){
			a[i] = new int[n];
			for(int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		cout << solve(m, n, a) << endl;
	} 
}
