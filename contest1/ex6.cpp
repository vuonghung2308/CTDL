#include <iostream>
using namespace std;

void generateFirst(int a[], int n) {
	for(int i = 0; i < n; i++)
		a[i] = i + 1;
}

void generateNext(int a[], int n, bool &isok) {
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
	} else isok = true;
}

void show(int a[], int n) {
	for(int i = 0; i < n; i++)
			cout << a[i];
		cout << ' ';
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		int a[n]; bool isok = false;
		generateFirst(a, n);
		while(!isok) {
			show(a, n);
			generateNext(a, n, isok);
		}
		cout << endl;
	}
}
