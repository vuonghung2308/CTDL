#include <bits/stdc++.h>
using namespace std;

int Prim(int s, int v, int **a) {
	int vt[v] = {s}, nvt = 1, mincost = 0;
	bool visited[v] = {}; visited[s] = true;
	while(nvt != v) {
		int min = INT_MAX, y;
		for(int i = 0; i < nvt; i++) {
			int x = vt[i];
			for(int j = 0; j < v; j++)
				if(!visited[j] && min > a[x][j] && x != j) {
					min = a[x][j];
					y = j;
				}			
		}
		vt[nvt++] = y;
		visited[y] = true;
		mincost = mincost + min;		
	}
	return mincost;
}

int main() {
	int t; cin >> t;
		for(int x = 0; x < t; x++) {
		int v, e; cin >> v >> e;
		int **a = new int*[v];
		for(int i = 0; i < v; i++) {
			a[i] = new int[v];
			for(int j = 0; j < v; j++) {
				if(i == j) a[i][j] = 0;
				else a[i][j] = INT_MAX;
			}	
		}
		for(int i = 0; i < e; i++) {
			int x, y, z; cin >> x  >> y >> z;
			a[x-1][y-1] = z;
			a[y-1][x-1] = z;
		}
		cout << Prim(0, v, a) << endl;
	}
}
