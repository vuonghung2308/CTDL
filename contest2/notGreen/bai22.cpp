#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, int **a) {
	return x < n && y < n && a[x][y];
}

int Try(int x, int y, int n, int **a, string result, bool &has) {
	if(isSafe(x+1, y, n, a)) {
		result.push_back('D');
		if(x+1 == n-1 && y == n-1) {
			cout << result << ' ';
			has = true;
		}
		else Try(x+1, y, n, a, result, has);
		result.erase(result.end()-1);
	}
	
	if(isSafe(x, y+1, n, a)) {
		result.push_back('R');
		if(x == n-1 && y+1 == n-1) {
			cout << result << ' ';
			has = true;
		}
		else Try(x, y+1, n, a, result, has);
		result.erase(result.end()-1);
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int **a = new int*[n];
		bool has = false;
		string result;
		for(int i = 0; i < n; i++) {
			a[i] = new int[n];
			for(int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		Try(0, 0, n, a, result, has);
		if(!has)
			cout << "-1";
		cout << endl;
	}
}

