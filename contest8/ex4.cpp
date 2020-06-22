#include <bits/stdc++.h>
using namespace std;

long long solve(string str, int k) {
	int a['Z'-'A'+1] = {}, i = 0;
	long long res = 0;
	priority_queue<int> q;
	for(int i = 0; i < str.size(); i++)
		a[str[i]-'A']++;
	sort(a, a+'Z'-'A'+1, greater<int>());
	while(i < 'Z'-'A'+1 && a[i] != 0)
		q.push(a[i++]);
	while(k-- && q.top() != 0) {
		q.push(q.top()-1);
		q.pop();
	}
	while(!q.empty()) {
		res = res + (long long) q.top()*q.top();
		q.pop();
	}
	return res;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int k; string str; cin >> k >> str;
		cout << solve(str, k) << endl;
	}
}
