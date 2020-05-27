#include <bits/stdc++.h>
using namespace std;

string toStr(long long a) {
	string res;
	while(a) {
		res.insert(res.begin(), '0' + a % 10);
		a =(long long) a / 10;
	}
	return res;
}
bool check(string sou, string tar) {
	int nt = tar.size();
	int ns = 0;
	for(int i = 0; i < nt; i++) {
		if(tar[i] == sou[ns])
			ns++;
		if(ns ==  sou.size())
			return true;
	}
	return false;
}

string generate(long long n) {
	vector<string> res;
	string tar = toStr(n);
	long long x = pow(n, (float) 1/3);
	for(x; x >= 1; x--) {
		string sou = toStr(x*x*x);
		if(check(sou, tar))
			return sou;
	}
	return "-1";
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		long long n; cin >> n;
		cout << generate(n) << endl;
	}
}
