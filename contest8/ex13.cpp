#include <iostream>
using namespace std;

bool check(int x) {
	int used[6] = {};
	while(x) {
		if(x%10 > 5 || used[x%10] > 0)
			return false;
		used[x%10] ++;
		x = x / 10;
	}
	return true;
}

int count(int l, int r) {
	int c = 0;
	for(int i = l; i <= r; i++) {
		if(check(i))
			c = c + 1;
	}
	return c;
}

int main() {
	int t; cin >> t;
		for(int i = 0; i < t; i++) {
		int l, r; cin >> l >> r;
		cout << count(l, r) << endl;
	}
}
