#include <iostream>
using namespace std;

long long pow(int x, long long n, long long mod) {
	if(n == 0) return 1;
	if(n == 1) return (long long) x % mod;
	if(n%2 == 0) {
		long long t = pow(x, n/2, mod);
		return (long long) (t * t)%mod;
	} else {
		long long t = pow(x, n/2, mod);
		return (long long) (((t * t)%mod)*x)%mod;
	}
}

int main() {
	long long mod = 123456789;
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		long long n; cin >> n;
		cout << pow(2, n-1, mod) << endl;
	}
}
