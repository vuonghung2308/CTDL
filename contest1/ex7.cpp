#include <bits/stdc++.h>
using namespace std;

void generateFirst(int *a, int n) {
	a[0] = n;
	for(int i = 1; i < n; i++)
		a[i] = 0;
}

void show(int *a, int n) {
	cout << '(';
	int i = 0;
	while(a[i+1]!=0 && i < n-1)
		cout << a[i++] << ' ';
	cout << a[i] << ") ";
}

void generateNext(int *a, int n, bool &isOk) {
	int i = n-1, t = 1;
	while(i >= 0 && (a[i]==1||a[i]==0)) {
		t = t + a[i];
		a[i] = 0;
		i = i - 1;
	}
	if(i >= 0) {
		a[i] = a[i] - 1;
		int x = t / a[i];
		int y = t % a[i];
		for(int j = 1; j <= x; j++)
			a[i+j] = a[i];
		a[i+x+1] = y;
	} else isOk = true;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		int a[n];
		bool isOk = false;
		generateFirst(a, n);
		while(!isOk) {
			show(a, n);
			generateNext(a, n, isOk);
		}
		cout << endl;
	}
}
