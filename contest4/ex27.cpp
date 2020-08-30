#include <bits/stdc++.h>
using namespace std;

long long daq(long long n, long long l, long long r) {
	long long x =  log(n) / log(2);
	x = (long long) (pow(2, x) - 1)*2 + 1;
	long long mid = x/2+1;
	if(l == r && l == mid) return n % 2;
	if(l < mid && r < mid) {
		return daq(n/2, l, r);
	}
	if(l > mid && r > mid) {
		return daq(n/2, l-mid, r-mid);
	}
	if(l == mid) return (long long) n%2 + daq(n/2, 1, r-mid);
	if(r == mid) return (long long) n%2 + daq(n/2, l, mid);
	return (long long) daq(n/2, l, mid-1) + n%2 + daq(n/2, 1, r-mid);
	
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		long long n, l, r; cin >> n >> l >> r;
		cout << daq(n, l, r) << endl;
	}
}
