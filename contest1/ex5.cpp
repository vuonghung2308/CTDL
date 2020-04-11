#include <iostream>
using namespace std;

void generateFirst(int a[], int k) {
	for(int i = 0; i < k; i++)
		a[i] = i + 1;
}

void generateNext(int a[], int k, int n, bool &isok) {
	int i = k-1;
	while(a[i] == n+i+1-k)
		i--;
	if(i >= 0) {
	int t = (i >= 0)?a[i]:0;
	for(int j = i; j < k; j++)
		a[j] = ++t;
	} else isok = true;
}

void show(int a[], int k) {
	for(int i = 0; i < k; i++)
			cout << a[i];
		cout << ' ';
}


int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		int a[k]; bool isok = false;
		generateFirst(a, k);
		while(!isok) {
			show(a, k);
			generateNext(a, k, n, isok);
		}
		cout << endl;
	}
}
