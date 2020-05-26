#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void sort(int *a, int n) {
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}

void showResult(int *a, int *result, int n, bool &has) {
	has = true;
	cout << '[';
	for(int i = 0; i < n-1; i++)
		cout << a[result[i]] << ' ';
	cout << a[result[n-1]] << "] ";
}

void Try(int i, int n, int *a, int *result, int sum ,int s, bool &has) {
	int j = (i == 0)?0:result[i-1]+1;
	for(j; j < n; j++) {
		result[i] = j;
		if(sum+a[j] <= s) {
			if(sum+a[j] == s)
				showResult(a, result, i+1, has);
			else Try(i+1, n, a, result, sum+a[j], s, has);
		}
	}	
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, s;
		bool has = false;
		cin >> n >> s;
		int *a = new int[n];
		int *result = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, n);
		Try(0, n, a, result, 0, s, has);
		if(!has)
			cout << "-1";
		cout << endl;
	}
}
