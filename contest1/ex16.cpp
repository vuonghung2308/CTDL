#include <bits/stdc++.h>
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

bool check(int **d, int a[], int n, int s) {
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += d[i][a[i]-1];
	return s == sum;
}

int main() {
	int n, s, t = 0; cin >> n >> s;
	int **m = new int*[n];
	int a[n]; bool isok = false;
	vector<int> res;
	generateFirst(a, n);
	
	
	for(int i = 0; i < n; i++) {
		m[i] = new int[n];
		for(int j = 0; j < n; j++)
			cin >> m[i][j];
	}
	
	
	while(!isok) {
		if(check(m, a, n, s))
			for(int i = 0; i < n; i++)
				res.push_back(a[i]);
		generateNext(a, n, isok);
	}
	
	
	cout << res.size()/n << endl;
	for(int i = 0; i < res.size()/n; i++) {
		for(int j = 0; j < n; j++)
			cout << res[t++] << ' ';
		cout << endl;
	}
}
