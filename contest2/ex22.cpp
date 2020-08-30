#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, int **a) {
	return x < n && y < n && a[x][y] == 1;
}

int Try(int x, int y, int n, int k, int **a, char *result, bool &has) {
	if(isSafe(x+1, y, n, a)) {
		result[k] = 'D';
		if(x+1 == n-1 && y == n-1 && k == 2*n-3) {
			cout << result << ' ';
			has = true;
		}
		else if(x+1 < n-1 || y < n-1) Try(x+1, y, n, k+1, a, result, has);
	}
	
	if(isSafe(x, y+1, n, a)) {
		result[k] = 'R';
		if(x == n-1 && y+1 == n-1 && k == 2*n-3) {
			cout << result << ' ';
			has = true;
		}
		else if(x < n-1 || y+1 < n-1) Try(x, y+1, n, k+1, a, result, has);
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int **a = new int*[n];
		bool has = false;
		char *result = new char[2*n-2];
		result[2*n-2] = '\0';
		for(int i = 0; i < n; i++) {
			a[i] = new int[n];
			for(int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		if(a[0][0] == 1)
			Try(0, 0, n, 0, a, result, has);
		if(!has)
			cout << "-1";
		cout << endl;
	}
}

