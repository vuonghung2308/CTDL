#include <bits/stdc++.h>
using namespace std;

int check(int v, vector<vector<int> > list) {
	int d = 0;
	for(int i = 0; i < v; i++)
		if(list[i].size()%2==1)
			d = d + 1;
	if(d == 0) return 2;
	else if(d == 2) return 1;
	return 0;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int v, e; cin >> v >> e;
		vector<vector<int> > list(v, vector<int>());
		for(int i = 0; i < e; i++) {
			int begin, end; cin >> begin >> end;
			list[begin-1].push_back(end-1);
			list[end-1].push_back(begin-1);
		}
		cout << check(v, list) << endl;
	}
}
