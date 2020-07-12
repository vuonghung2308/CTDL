#include <bits/stdc++.h>
using namespace std;

void show(int *a, int n) {
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void sort(int *a, int n) {
	for(int i = 0; i < n-1; i++) {
		int mi = i+1;
		for(int j = i+2; j < n; j++)
			if(a[mi] > a[j])
				mi = j;
		if(a[i] > a[mi])
			swap(a[i], a[mi]);
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
