#include <iostream>
using namespace std;

int findL(int n, int *a) {
	int *l = new int[n];
	int m = 1;
	l[0] = 1;
	for(int i = 1; i < n; i++) {
		int t = 1;
		for(int j = 0; j < i; j++) 
			if(a[j] < a[i] && l[j]+1 > t)
				t = l[j] + 1;
		l[i] = t;
		m = max(m, t);
	}
	return m;
}

int main() {
	int n; cin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << findL(n, a);
}
