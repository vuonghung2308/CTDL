#include <bits/stdc++.h>
using namespace std;

int sumClosest(int *a, int n) {
	int s = INT_MAX;
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if(abs(s) > abs(a[i] + a[j]) )
				s = a[i] + a[j];
	return s;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << sumClosest(a, n) << endl;
	}
}
