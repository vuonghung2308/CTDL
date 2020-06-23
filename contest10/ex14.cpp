#include <bits/stdc++.h>
using namespace std;

void Dijkstra(int **a, int *truoc, int n, int s) {
	bool visited[n] = {};
	int d[n] = {};
	int t = n-1, mind;
	visited[s] = true;
	for(int i = 0; i < n; i++) {
		truoc[i] = s;
		d[i] = a[s][i];		
	}
	
	while(t) {
		mind = INT_MAX;
		int u = 0;
		for(int i = 0; i < n; i++) {
			if(!visited[i] && mind > d[i]) {
				mind = d[i];
				u = i;
			}
		}
		visited[u] = true; t--;
		for(int i = 0; i < n; i++) {
			if(d[i] > d[u] + a[u][i] ) {
				d[i] = d[u] + a[u][i];
				truoc[i] = u;
			}
		}
	}
	
	for(int i = 0; i < n; i++)
		cout << d[i] << ' ';
	cout << endl;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, c, s; cin >> n >> c >> s;
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
			if( a[begin-1][end-1] > d){
				a[begin-1][end-1] = d;
				a[end-1][begin-1] = d;
			}
		}
		Dijkstra(a, truoc, n, s-1);
	}
}

