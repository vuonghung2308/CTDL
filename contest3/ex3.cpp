#include <bits/stdc++.h>
using namespace std;

int greedy(int n, int *a) {
	int x = 0;
	const int MAX = 1000000000 + 7; 
	for(int i = 0; i < n; i++)
		x = (x + (a[i]*i)%MAX) % MAX;
	return x;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);
		cout << greedy(n, a) << endl;
	}
}
