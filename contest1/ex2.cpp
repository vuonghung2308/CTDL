#include <iostream>
using namespace std;

void generateNext(int a[], int k, int n) {
	int i = k-1;
	while(a[i] == n+i+1-k)
		i--;
	int t = (i >= 0)?a[i]:0;
	i = (i >= 0)?i:0;
	for(int j = i; j < k; j++)
		a[j] = ++t;
}


int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		int a[k];
		for(int j = 0; j < k; j++)
			cin >> a[j];
		generateNext(a, k, n);
		for(int j = 0; j < k; j++)
			cout << a[j] << ' ';
		cout << endl;
	}
}
