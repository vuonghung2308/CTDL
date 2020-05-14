#include <iostream>
using namespace std;

int greedy(int n, int *c) {
	int i = 9, d = 0;
	while(n != 0) {
		while(n >= c[i]) {
			d++;
			n = n -c[i];
		}
		i--;
	}
	return d;
}

int main() {
	int c[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		cout << greedy(n, c) << endl;
	}
}
