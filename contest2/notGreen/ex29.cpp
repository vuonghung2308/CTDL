#include <iostream>
using namespace std;

void Try(int x, int y, int n, int m, int &d) {
	if(x == m-1 && y == n-1)
		d++;
	if(x+1 < m && y < n) Try(x+1, y, n, m, d);
	if(x < m && y+1 < n) Try(x, y+1, n, m, d);
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int m, n, d = 0, **a;
		cin >> m >> n;
		a = new int*[m];
		for(int i = 0; i < m; i++) {
			a[i] = new int[n];
			for(int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		Try(0, 0, n, m, d);
		cout << d << endl;
	}
}
