#include <bits/stdc++.h>
using namespace std;

vector<int> split(long long n) {
	vector<int> a;
	while(n) {
		a.insert(a.begin(), n%10);
		n = n / 10;
	}
	return a;
}

long long combine(vector<int> a, int l, int r) {
	long long res = 0;
	for(int i = l; i <= r; i++)
		res = res*10 + a[i];
	return res;
}

long long solve(long long n) {
	vector<int> a = split(n);
	int na = a.size();
	long long s[na+1] = {};
	for(int i = 1; i <= na; i++) {
		s[i] = s[i-1];
		for(int j = i; j >= 1; j--)
			s[i] = s[i] + combine(a, j-1, i-1);
	}
	return s[na];
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		long long n; cin >> n;
		cout << solve(n) << endl;
	}
}
