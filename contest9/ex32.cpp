#include <bits/stdc++.h>
using namespace std;
int move[][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
				,{0, 1}, {0, -1}, {1, 0}, {-1, 0} };
				
bool isOk(int i, int j, int n, int m, int **a) {
	return i < n && i >= 0 && j < m && j >= 0 && a[i][j] == 1;
}

void BFS(int i, int j, int n, int m, int **a, bool **visited) {
	queue<pair<int, int> > queue; queue.push(pair<int, int>(i, j));
	visited[i][j] = true;
	while(!queue.empty() ) {
		i = queue.front().first;
		j = queue.front().second;
		queue.pop();
		for(int x = 0; x < 8; x++) {
			int ni = i + move[x][0];
			int nj = j + move[x][1];
			if(isOk(ni, nj, n, m, a) && !visited[ni][nj]) {
				visited[ni][nj] = true;
				queue.push(pair<int, int>(ni, nj));
			}
		}
	}
}

int count(int n, int m, int **a, bool **visited) {
	int s = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!visited[i][j] && a[i][j] == 1) {
				s = s + 1;
				BFS(i, j, n, m, a, visited);
			}
		}
	}
	return s;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, m; cin >> n >> m;
		int **a = new int*[n];
		bool **visited = new bool*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[m];
			visited[i] = new bool[m];
			for(int j = 0; j < m; j++) {
				cin >> a[i][j];
				visited[i][j] = false;
			}
		}
		cout << count(n, m, a, visited) << endl;
	}
}
