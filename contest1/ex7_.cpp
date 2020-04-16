#include <iostream>
using namespace std;

void show(int a[], int n) {
	cout << '(';
	for(int i = 1; i < n; i++)
		cout << a[i] << ' ';
	cout << a[n] << ") ";
}

void Try(int a[], int i, int n, int sum) {
	for(int j = a[i-1]; j >= 1; j--) {
		if(sum + j == n) {
			a[i] = j;
			show(a, i);
		} else if(sum + j < n) {
			a[i] = j;
			Try(a, i+1, n, sum + j);
		}
	}
	
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		int a[n+1] = {n};
		Try(a, 1, n, 0);
		cout << endl;
	}
}
