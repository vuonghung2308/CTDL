#include <bits/stdc++.h>
using namespace std;

void convert(int **a, int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 1)
				cout << j+1 << ' ';
		}
		cout << endl;
	}
}


int main() {
	int n; cin >> n;
	int **a = new int*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	convert(a, n);
}
