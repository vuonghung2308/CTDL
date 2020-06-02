#include <iostream>
using namespace std;

int Find(long long *a, long long *a_, int l, int r) {
	if(r-l == 1) {
		if(a[l] != a_[l]) return l+1;
		else return r+1;
	}
	int mid = (l+r)/2;
	if(a[mid] != a_[mid] && (mid-1 < l || a[mid-1] == a_[mid-1]) )
		return mid+1;
	if(a[mid] == a_[mid])
		return Find(a, a_, mid+1, r);
	return Find(a, a_, l, mid-1);
	
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		long long *a = new long long[n];
		long long *a_ = new long long[n-1];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n-1; i++)
			cin >> a_[i];
		cout << Find(a, a_, 0, n-1) << endl;
	}
}
