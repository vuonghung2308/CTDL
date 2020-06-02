#include <bits/stdc++.h>
using namespace std;

long long dao(long long x) {
	long long res = 0;
	while(x) {
		res = res*10 + x%10;
		x = x / 10;
	}
	return res;
}

long long pow(long long x, long long n, long long mod) {
	if(n == 1) return x%mod;
	long long t = pow(x, n/2, mod)%mod;
	if(n%2 == 0) return (t*t) % mod;
	else return (x*((t*t)%mod))% mod;
}

int main() {
	long long mod = 1000000000+7;
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		long long x;
		cin >> x;
		long long n = dao(x);
		cout << pow(x, n, mod) << endl;
	}
}
