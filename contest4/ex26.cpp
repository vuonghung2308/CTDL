// Lam theo web co so bo test

#include <iostream>
using namespace std;

string sum(string a, string b, int k) {
	string res; int c = 0;
	for(int i = a.size()-1; i >= 0; i--) {
		int x = a[i] - '0';
		int y = b[i] - '0';
		res.insert(res.begin(), '0' + (x+y+c)%k);
		c = (x + y + c) / k;
	}
	if(c > 0) res.insert(res.begin(), '0' + c);
	return res;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
	string a, b; int k;
	cin >> k >> a >> b;
		while(a.size() < b.size())
			a.insert(a.begin(), '0');
		while(b.size() < a.size())
			b.insert(b.begin(), '0');
		cout << sum(a, b, k) << endl;
	}
}
