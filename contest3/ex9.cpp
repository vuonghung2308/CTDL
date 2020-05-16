#include <bits/stdc++.h>
using namespace std;

bool Greater(int *x, int *y) {
	return x[1] > y[1];
}

void greedy(int **a, int n) {
	bool slot[n] = {};
	int profit = 0, count = 0;
	sort(a, a+n, Greater);
	for(int i = 0; i < n; i++) {
		for(int j = min(n, a[i][0])-1; j >= 0; j--) {
			if(slot[j] == false) {
				count = count + 1;
				profit = profit + a[i][1];
				slot[j] = true;
				break;
			}
		}
	}
	cout << count << ' ' << profit << endl;	
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int **a = new int*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[2];
			int t;
			cin >> t >> a[i][0] >> a[i][1];
		}
		greedy(a, n);
	}
}
