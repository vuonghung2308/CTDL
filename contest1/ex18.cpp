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

bool check(int a[], long long m[], int k, long long s) {
	long long sum = 0;
	for(int i = 0; i < k; i++)
		sum += m[a[i]-1];
	return s == sum;
}


int main() {
	int t;
	long long s;
	cin >> t >> s;
	long long m[t];
	for(int i = 0; i < t; i++)
		cin >> m[i];
	for(int i = 1; i <= t; i++) {
		int a[i]; bool isok = false;
		generateFirst(a, i);
		while(!isok) {
			if(check(a, m, i, s)) {
				cout << i;
				return 0;
			}
			generateNext(a, i, t, isok);
		}
	}
	cout << -1;
}
