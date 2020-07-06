#include <bits/stdc++.h>
using namespace std;

void BFS_Queue(int v, int **a, int n, bool *visited) {
	queue<int> queue;
	queue.push(v);
	visited[v] = true;
	while(!queue.empty()) {
		v = queue.front();
		queue.pop();
		for(int i = 0; i < n; i++) {
			if(a[v][i] == 1 && !visited[i]) {
				visited[i] = true;
				queue.push(i);
			}
		}
	}
}

bool StrongConnnected(int **a, int n, bool *visited) {
	int count = 0;
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			BFS_Queue(i, a, n, visited);
			count = count + 1;
		}
	}
	return count == 1;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int v, e, **a; cin >> v >> e;
		bool visited[v] = {};
		a = new int*[v];
		for(int i = 0; i < v; i++)
			a[i] = new int[v];
		for(int i = 0; i < e; i++) {
			int begin, end; cin >> begin >> end;
			if(begin >= 0 && begin <= v && end >= 0 && end <= v)
				a[begin-1][end-1] = 1;
		}
		if(StrongConnnected(a, v, visited) )
			cout << "YES\n";
		else cout << "NO\n";
	}
}
