#include <iostream>
using namespace std;

long long mul(string a, string b) {
	long long x = 0, y = 0;
	for(int i = 0; i < a.size(); i++)
		x = x*2 + (a[i] - '0');
	for(int i = 0; i < b.size(); i++)
		y = y*2 + (b[i] - '0');
	return x*y;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		string a, b; cin >> a >> b;
		cout << mul(a, b) << endl;
	}
}
