#include <bits/stdc++.h>
using namespace std;

bool greedy(int n, int *a, int *a_) {
	sort(a_, a_+n);
	for(int i = 0; i < n; i++)
		if(!(a[i] == a_[i]) && !(a[n-1-i] == a_[i]))
			return false;
	return true;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int *a = new int[n];
		int *a_ = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			a_[i] = a[i];
		}
		if(greedy(n, a, a_)) cout << "Yes\n";
		else cout << "No\n";
	}
}
