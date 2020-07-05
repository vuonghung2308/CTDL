#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int v, e; cin >> v >> e;
		int begin, end;
		vector<vector<int> > list(v, vector<int>());
		for(int i = 0; i < e; i++) {
			cin >> begin >> end;
			list[begin-1].push_back(end);
		}
		for(int i = 0; i < v; i++) {
			cout << i+1 << ':';
			for(int j = 0; j < list[i].size(); j++)
				cout << ' ' << list[i][j];
			cout << endl;
		}
	}
}
