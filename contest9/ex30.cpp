#include <bits/stdc++.h>
using namespace std;

bool check(int v, int deg[][2]) {
	int d = 0;
	for(int i = 0; i < v; i++)
		if(deg[i][0] == deg[i][1])
			d = d + 1;
	return d == v;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int v, e; cin >> v >> e;
		int deg[v][2] = {};
		for(int i = 0; i < e; i++) {
			int begin, end; cin >> begin >> end;
			deg[end-1][0] ++;
			deg[begin-1][1] ++;
		}
		cout << check(v, deg) << endl;
	}
}
