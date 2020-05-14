#include <bits/stdc++.h>
using namespace std;

long long greedy(int n, int *a) {
	long long x1 = 0, x2 = 0;
	int i = 0;
	while(i < n) {
		if(x1 < x2) x1 = (long long) (x1*10 + a[i]);
		else x2 = (long long) (x2*10 + a[i]);
		i = i + 1;
	}
	return x1+x2;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n, less<int>());
		cout << greedy(n, a) << endl;	
	}
}
