#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		long long n, k;
		string s; cin >> s >> k;
		n = s.size();
		while(n < k) n = n * 2;
		while(n > s.size()) {
			if(k > n/2) {
				k = k - n/2;
				if(k > 1) k = k - 1;
				else k = n / 2;
			}
			n = n / 2;
		}
		cout << s[k-1] << endl;
	}
}
