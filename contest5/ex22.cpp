#include <iostream>
using namespace std;

int solve(int *a, int n) {
	long long max_end_of_here = a[0];
	long long max_so_far = 0;
	for(int i = 1; i < n; i++) {
		long long t = max_end_of_here;
		max_end_of_here = max(max_so_far+a[i], max_end_of_here);
		max_so_far = t;		
	}
	return (max_end_of_here > max_so_far)?max_end_of_here:max_so_far;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << solve(a, n) << endl;
	}
}
