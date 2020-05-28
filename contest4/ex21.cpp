#include <iostream>
using namespace std;

long long pow(int x, int n, long long mod) {
	if(n == 0)
		return 1;
	if(n == 1) return (long long) x % mod;
	if(n%2 == 0) {
		long long t =(long long) pow(x, n/2, mod) % mod;
		return (long long) (t*t) % mod;
	} else {
		long long t = (long long) pow(x, n/2, mod) % mod;
		return (long long) ( ((t*t)%mod) * (x%mod ) ) % mod;
	}
}

int main() {
	const long long mod = 1000000000+7;
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int x, n;
		cin >> x >> n;
		cout << pow(x, n, mod) << endl;
	}
}
