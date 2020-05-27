#include <iostream>
using namespace std;

int greedy(int n, int s, int m) {
	int c = 0, d = 0;
	for(int i = 1; i <= s; i++) {
		if(i%7 != 0) {
			c = c + n;
			d++;
		}
		if(c >= s*m)
			return d;
		if(c < i*m) return -1;
	}
	return -1;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, s, m;
		cin >> n >> s >> m;
		cout << greedy(n, s, m) << endl;
	}
}
