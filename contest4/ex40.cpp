#include <iostream>
using namespace std;

int count(int *a, int l, int r) {
	if(a[l] == 0 && a[r] == 0) return r-l+1;
	if(a[l] == 1) return 0;
	int mid = (l+r) / 2;
	if(a[mid] == 1) return count(a, l, mid-1);
	if(a[mid] == 0) return mid-l+1 + count(a, mid+1, r);
	
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << count(a, 0, n-1)<< endl;
	}
}
