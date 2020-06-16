#include <iostream>
using namespace std;

string add(string a, string b) {
	string res;
	int c = 0;
	while(a.size() < b.size())
		a.insert(a.begin(), '0');
	while(b.size() < a.size())
		b.insert(b.begin(), '0');
	for(int i = a.size()-1; i >= 0; i--) {
		int s = a[i] + b[i] + c -'0'*2;
		res.insert(res.begin(), (s%10) + '0');
		c = s / 10;
	}
	if(c!=0) res.insert(res.begin(), c + '0');
	return res;
}

string mul(string a, string b) {
	if(a < b) return mul(b, a);
	int na = a.size(), nb = b.size(), c, s, nr;
	string res = "";
	
	for(int i = nb-1; i >= 0; i--) {
		c = 0;
		for(int j = na-1; j >= 0; j--) {
			nr = res.size();
			s = c + (a[j]-'0')*(b[i]-'0');
			if(nb-i+na-j-1 <= nr) {
				s = s + res[nr-na-nb+i+j+1] - '0';
				res[nr-na-nb+i+j+1] = s%10 + '0';
			} else res.insert(res.begin(), s%10 +'0');
			c = s / 10;
		}
		if(c != 0) res.insert(res.begin(), c+'0');
	}	
	
	return res;
}

string solve(int n) {
	string a[n+1];
	a[0] = "1";
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < i; j++)
			a[i] = add(a[i], mul(a[j],a[i-j-1]));
	}
	return a[n];
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		cout << solve(n) << endl;
	}
}
