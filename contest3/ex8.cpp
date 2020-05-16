#include <bits/stdc++.h>
using namespace std;

bool Less(int *x, int *y) {
	return x[1] < y[1];
}

void greedy(int n, int **cv) {
	int count = 1, i = 0;
	for(int j = 1; j < n; j++) {
		if(cv[j][0] >= cv[i][1])
			count++, i = j;
	}
	cout << count << endl;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int **cv = new int*[n];
		for(int i = 0; i < n; i++) {
			cv[i] = new int[2];
			cin >> cv[i][0];
		}
		for(int i = 0; i < n; i++)
			cin >> cv[i][1];
		sort(cv, cv+n, Less);
		greedy(n, cv);
	}
	
}
