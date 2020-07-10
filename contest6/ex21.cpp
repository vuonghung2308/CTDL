#include <bits/stdc++.h>
using namespace std;

struct num{
	int value;
	int amount;
};

bool Compare(num a, num b) {
	if(a.amount == b.amount)
		return a.value < b.value;
	return a.amount > b.amount;	
}

void solve(int n, int *a, set<int> s) {
	sort(a, a+n);
	int am_of_set = s.size(), n_nu = 0;
	num nums[am_of_set];
	set<int>::iterator it = s.begin();
	set<int>::iterator end = s.end();
	while(it != end) {
		int count = upper_bound(a, a+n, *it)
			- lower_bound(a, a+n, *it);
		nums[n_nu].amount = count;
		nums[n_nu++].value = *(it++);
	}
	sort(nums, nums + n_nu, Compare);
	for(int i = 0; i < n_nu; i++) {
		for(int j = 0; j < nums[i].amount; j++)
			cout << nums[i].value << ' ';
	}
	cout << endl;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, na = 0; cin >> n;
		int a[n];
		set<int> set;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			set.insert(a[i]);
		}
		solve(n, a, set);
	}
}
