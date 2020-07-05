#include <bits/stdc++.h>
using namespace std;

void BFS_Queue(int v, int **a, int n, bool *visited) {
	queue<int> queue;
	queue.push(v);
	visited[v] = true;
	while(!queue.empty()) {
		v = queue.front();
		cout << v+1 << ' ';
		queue.pop();
		for(int i =0; i < n; i++) {
			if(a[v][i] && !visited[i]) {
				visited[i] = true;
				queue.push(i);
			}
		}
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int v, e, s; cin >> v >> e >> s;
		bool visited[v] = {};
		int **a = new int*[v];
		for(int i = 0; i < v; i++)
			a[i] = new int[v];
		for(int i = 0; i < e; i++) {
			int start, end; cin >> start >> end;
			a[start-1][end-1] = 1;
			a[end-1][start-1] = 1;
		}
		BFS_Queue(s-1, a, v, visited);
	}
}
