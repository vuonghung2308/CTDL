#include <iostream>
using namespace std;

int solve(int *a, int n, int k) {
	int s[k][n+1] = {};
	for(int j = 1; j <= n; j++) {		
		for(int i = 0; i < k; i++) {
			if(a[j-1]%k == i && s[i][j-1] == 0)
				s[i][j] = 1;
			else {
				int x = (k+i-(a[j-1]%k))%k;
				if(s[x][j-1] != 0)
					s[i][j] = max(s[x][j-1]+1, s[i][j-1]);
				else
					s[i][j] = s[i][j-1];
			}
		}
	}
	return s[0][n];
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, k; cin >> n >> k;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << solve(a, n, k) << endl;
	}
}
