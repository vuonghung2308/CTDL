#include <bits/stdc++.h>
using namespace std;

void greedy(string s, int k) {
	int n = 0, x[256] = {};
	long long res = 0;
	for(int i = 0; i < s.size(); i++) {
		if(x[s[i]] == 0)
			n++;
		x[s[i]]++;
	}
	sort(x, x+256, greater<int>());
	priority_queue<int, vector<int>, less<int> > Q(x, x+n);
	for(int i = 0; i < k && Q.top()>0; i++) {
		int t = Q.top() - 1; Q.pop();
		Q.push(t);
	}
	
	while(!Q.empty()) {
		res += (long long) Q.top() * Q.top();
		Q.pop();
	}
	
//	for(int i = 0; i < n - k; i++)
//		res += (long long) x[i] * x[i];
	cout << res <<endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int k;	string s;
		cin >> k >> s;
		greedy(s, k);
	}
}
