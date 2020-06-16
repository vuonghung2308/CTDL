#include <bits/stdc++.h>
using namespace std;

struct Pair{
	int t;
	int s;
};

bool Less(Pair x, Pair y) {
	return x.t < y.t;
}

int solve(Pair *a, int n) {
	int c[n] = {1};
	int m = 0;
	sort(a, a+n, Less); 			// phai sap xep thi moi dung 
	for(int i = 1; i < n; i++) {	//(vd voi 1 2 5 24 3 5 dung la 2 khong sap xep thi ra 1
		c[i] = 1;
		for(int j = 0; j < i; j++)
			if(a[i].t > a[j].s && c[i] < c[j] + 1)
				c[i] = c[j] + 1;
		if(c[i] > m)
			m = c[i];
	}
	return m;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		Pair *a = new Pair[n];
		for(int i = 0; i < n; i++)
			cin >> a[i].t >> a[i].s;
		cout << solve(a, n) << endl;
	}
}
