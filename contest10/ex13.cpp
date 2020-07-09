#include <bits/stdc++.h>
using namespace std;

void BellmanFord(int **a, int *truoc, int n, int s) {
	int d[n] = {};
	for(int i = 0; i < n; i++) {
		truoc[i] = s;
		d[i] = a[s][i];		
	}
	
	for(int k = 0; k < n-1; k++) {
		for(int v = 0; v < n; v++) {
			if(v != s) {
				for(int u = 0; u < n; u++) {
					if(d[v] > d[u] + a[u][v]) {
						d[v] = d[u] + a[u][v];
						truoc[v] = u;
					}
				}
			}
		}
	}
	bool chutrinhAm = false;
	for(int i = 0; i< n; i++)
		for(int j = 0; j < n; j++)
			if(d[i] > d[j]+a[j][i])
				chutrinhAm = true;
	if(chutrinhAm) cout << 1 << endl;
	else cout << 0 << endl;
}

int main() {
	int t; cin >> t; 
	for(int x = 0; x < t; x++) {
		int n, c; cin >> n >> c;
		int **a = new int*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[n];
			for(int j = 0; j < n; j++)
				if(i == j) 	a[i][j] = 0;
				else a[i][j] = SHRT_MAX;
		}
		int *truoc = new int[n];
		for(int i = 0; i < c; i++) {
			int begin, end, d;
			cin >> begin >> end >> d;
			a[begin-1][end-1] = d;
		}
		BellmanFord(a, truoc, n, 0);
	}
}

