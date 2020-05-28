#include <iostream>
using namespace std;

int binarysearch(int *a, int x, int l, int r) {
	if(l > r) 
		return -1;
	int m = (l + r) / 2;
	if(a[m] == x) 
		return m;
	if(a[m] < x) 
		return binarysearch(a, x, m+1, r);
	return binarysearch(a, x, l, m-1);
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, x; cin >> n >> x;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int t = binarysearch(a, x, 0, n-1);
		if(t != -1)
			cout << t+1 << endl;
		else cout << "NO" << endl;
	}
}
