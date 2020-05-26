#include <bits/stdc++.h>
using namespace std;

void show(int a[], int n, string s) {
	char res[n];
	for(int i = 0; i < n; i++)
		res[i] = s[a[i]];
	res[n] = '\0';
	cout << res << ' ';
}

void Try(int i, int a[], int visited[], int n, string s) {
	for(int x = 0; x < n; x++) {
		if(visited[x] == 0) {
			a[i] = x;
			visited[x] = 1;
			if(i == n-1)
				show(a, n, s);
			else Try(i+1, a, visited, n, s);
			visited[x] = 0;
		}
	}
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {	
		string s; cin >> s;
		int n = s.size();
		int a[n];
		int visited[n] = {0};
		Try(0, a, visited, n, s);
		cout << endl;
	}
}
