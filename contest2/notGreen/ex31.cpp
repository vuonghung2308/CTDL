#include <bits/stdc++.h>
using namespace std;

bool isOk(int x, int y, int m, int n, char **a, char c) {
	return x < m && x >= 0 && y < n && y >= 0 && a[x][y] == c;
}

void Try(int i, int x, int y, int m, int n, string str, char **a, bool &has) {
	
	if(isOk(x-1, y-1, m, n, a, (char) str[i]) && !has) {
		if(i == str.length()-1)
			has = true;
		else Try(i+1, x-1, y-1, m, n, str, a, has);
	}
	
	if(isOk(x-1, y, m, n, a, (char) str[i]) && !has) {
		if(i == str.length()-1) 
			has = true;
		else Try(i+1, x-1, y, m, n, str, a, has);
	}
	
	if(isOk(x-1, y+1, m, n, a, (char) str[i]) && !has) {
		if(i == str.length()-1) 
			has = true;
		else Try(i+1, x-1, y+1, m, n, str, a, has);
	}
	
	if(isOk(x, y+1, m, n, a, (char) str[i]) && !has) {
		if(i == str.length()-1) 
			has = true;
		else Try(i+1, x, y+1, m, n, str, a, has);
	}
	
	if(isOk(x+1, y+1, m, n, a, (char) str[i]) && !has) {
		if(i == str.length()-1)
			has = true;
		else Try(i+1, x+1, y+1, m, n, str, a, has);
	}
	
	if(isOk(x+1, y, m, n, a, (char) str[i]) && !has) {
		if(i == str.length()-1)
			has = true;
		else Try(i+1, x+1, y, m, n, str, a, has);
	}
	
	if(isOk(x+1, y-1, m, n, a, (char) str[i]) && !has) {
		if(i == str.length()-1)
			has = true;
		else Try(i+1, x+1, y-1, m, n, str, a, has);
	}
	
	if(isOk(x, y-1, m, n, a, (char) str[i]) && !has) {
		if(i == str.length()-1) 
			has = true;
		else Try(i+1, x, y-1, m, n, str, a, has);
	}
}

void check(int m, int n, string str, char **a) {
	bool has = false;
		for(int x = 0; x < m; x++) {
			for(int y = 0; y < n; y++) {
				if(a[x][y] == str[0])
					Try(1, x, y, m, n, str, a, has);
				if(has) break;
			}
			if(has) break;
		}
	if(has) cout << str << ' ';
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int w, m, n;
		cin >> w >> m >> n;
		string *str = new string[w];
		char **a = new char*[m];
		for(int i = 0; i < w; i++)
			cin >> str[i];
		for(int i = 0; i < m; i++) {
			a[i] = new char[n];
			for(int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		for(int i = 0; i < w; i++)
			check(m, n, str[i], a);
		cout << endl;
	}
}
