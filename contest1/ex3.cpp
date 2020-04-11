#include <iostream>
using namespace std;

void generateNext(int a[], int n) {
	int i = n - 2;
	while(a[i] > a[i+1])
		i--;
	if(i >= 0) {
		int t = n-1;
		while(a[t] < a[i])
			t--;
		int x = a[t]; a[t] = a[i]; a[i] = x;
		int b = i+1, e = n-1;
		while(b < e) {
			x = a[b]; a[b] = a[e]; a[e] = x;
			b++; e--;
		}
	} else {
		for(int i = 0; i < n; i++)
			a[i] = i+1;
	}
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		int a[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		generateNext(a, n);
		for(int j = 0; j < n; j++)
			cout << a[j] << ' ';
		cout << endl;
	}
}
