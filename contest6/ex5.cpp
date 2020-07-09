#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m, int *a, int *b) {
	vector<int> unio, inte;
	sort(a, a+n); sort(b, b+m);
	int i = 0, j = 0;
	while(i < n && j < m) {
		if(a[i] == b[j]) {
			unio.push_back(a[i++]);
			inte.push_back(b[j++]);
		} else if(a[i] < b[j]) {
			unio.push_back(a[i++]);
		} else unio.push_back(b[j++]);
	}
	while(i < n) unio.push_back(a[i++]);
	while(j < m) unio.push_back(b[j++]);
	for(i = 0; i < unio.size(); i++)
		cout << unio[i] << ' ';
	cout << endl;
	for(i = 0; i < inte.size(); i++)
		cout << inte[i] << ' ';
	cout << endl;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, m; cin >> n >> m;
		int *a = new int[n];
		int *b = new int[m];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < m; i++)
			cin >> b[i];
		solve(n, m, a, b);
	}
}
