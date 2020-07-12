#include <bits/stdc++.h>
using namespace std;

void show(int *a, int n) {
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void sort(int *a, int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
		cout << "Buoc " << i+1 << ": ";
		show(a, n);
	}
}

int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, n);
}
