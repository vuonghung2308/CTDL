#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
bool isPrime[MAX];

//ham sinh so nguyen to
void Prime() {
	memset(isPrime, true, MAX);
	isPrime[0] = isPrime[1] = false;
	for(long long i = 2; i < MAX; i++) {
		if(isPrime[i] == true) {
			for(long long j = i*i; j < MAX; j = j+i)
				isPrime[j] = false;
		}
	}
}

int main() {
	int t; cin >> t;
	Prime();
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		bool has = false;
		for(int i = 2; i < n; i++) {
			if(isPrime[i] && isPrime[n-i]) {
				cout << i << ' ' << n-i << endl;
				has = true;
				break;
			}
		}
		if(!has) cout << -1 << endl;
	}
}
