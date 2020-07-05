#include <bits/stdc++.h>
using namespace std;

void DFS_Stack(int v, int **a, int n, bool *visited) {
	cout << v+1 << ' ';
	stack<int> stack;
	stack.push(v);
	visited[v] = true;
	while(!stack.empty()) {
		v = stack.top();
		stack.pop();
		for(int i =0; i < n; i++) {
			if(a[v][i] == 1 && !visited[i]) {
				cout << i+1 << ' ';
				visited[i] = true;
				stack.push(v);
				stack.push(i);
				break;
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
		DFS_Stack(s-1, a, v, visited);
	}
}

