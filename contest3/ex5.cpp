#include <bits/stdc++.h>
using namespace std;

bool Greater(int x, int y) {return x > y;}

int greedy(int n, int k ,int *a) {
	int x = (k > n-k)?k:n-k;
	int s1 = 0, s2 = 0;
	int i = 0;
	while(i < x) {
		s1 += a[i];
		i++;
	}
	while(i < n) {
		s2 += a[i];
		i++;
	}
	return s1 - s2;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, k; cin >> n >> k;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		//sort(a, a+n, Greater); 
		sort(a, a+n, greater<int>());
		cout << greedy(n, k, a) << endl;
	}
}
