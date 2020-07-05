#include <bits/stdc++.h>
using namespace std;
int a[1000][1000] = {};

void show(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
}

void add(string s, int x, int n) {
	for(int i = 0; i < s.size(); i++) {
		int d = 0;
		while(isdigit(s[i]) ) {
			d = d * 10 + s[i] - '0';
			i = i + 1;
		}
		if(d < n && d > 0) {
			a[x][d-1] = 1;
			a[d-1][x] = 1;
		}
	}
}

int main() {
	int n; cin >> n; cin.ignore();

	for(int i = 0; i < n; i++) {
		string s = "";
		while(s == "")
			getline(cin, s);
		add(s, i, n);
	}
	
	show(n);
}
