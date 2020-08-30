#include <iostream>
using namespace std;

int a[11][11], b[100], c[11][11];
int x, y, check, n, l;

void khoitao() {
	x = 1; y = 1;
	c[11][11] = {};
	check = false;
}

void hienthi() {
	for(int i = 1; i <= l; i++) {
		if(b[i] == 1) cout << "D";
		if(b[i] == 2) cout << "L";
		if(b[i] == 3) cout << "R";
		if(b[i] == 4) cout << "U";
	}
	cout <<  " ";
}

void Try(int i) {
	if(x+1 <= n && a[x+1][y] && !c[x+1][y] && b[i-1] != 4) {
		x = x + 1;
		b[i] = 1;
		c[x][y] = 1;
		if(x == n && y == n) {
			l = i;
			hienthi();
			check = true;
		} else Try(i+1);
		c[x][y] = 0;
		x = x - 1;
	}
	
	if(y-1 > 0 && a[x][y-1] && !c[x][y-1] && b[i-1] != 3) {
		y = y - 1;
		b[i] = 2;
		c[x][y] = 1;
		if(x == n && y == n) {
			l = i;
			hienthi();
			check = true;
		} else Try(i+1);
		c[x][y] = 0;
		y = y + 1;
	}
	
	if(y+1 <= n && a[x][y+1] && !c[x][y+1] && b[i-1] != 2) {
		y = y + 1;
		b[i] = 3;
		c[x][y] = 1;
		if(x == n && y == n) {
			l = i;
			hienthi();
			check = true;
		} else Try(i+1);
		c[x][y] = 0;
		y = y - 1;
	}
	
	if(x-1 > 0 && a[x-1][y] && !c[x-1][y] && b[i-1] != 1) {
		x = x - 1;
		b[i] = 4;
		c[x][y] = 1;
		if(x == n && y == n) {
			l = i;
			hienthi();
			check = true;
		} else Try(i+1);
		c[x][y] = 0;
		x = x + 1;
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> a[i][j];
		khoitao();
		Try(1);
		if(!check)
			cout << -1;
		cout << endl;
	}
}
