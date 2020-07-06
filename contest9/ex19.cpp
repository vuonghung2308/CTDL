#include <bits/stdc++.h>
using namespace std;

void DFS_Stack(int v, int **a, int n, bool *visited) {
	stack<int> stack;
	stack.push(v);
	visited[v] = true;
	while(!stack.empty()) {
		v = stack.top();
		stack.pop();
		for(int i = 0; i < n; i++) {
			if(a[v][i] == 1 && !visited[i]) {
				visited[i] = true;
				stack.push(v);
				stack.push(i);
				break;
			}
		}
	}
}

bool CheckConnection(bool *visited, int n) {
	for(int i = 0; i < n; i++)
		if(!visited[i])
			return false;
	return true;
}

void ArticurationPoint(int **a, int n, bool *visited) {
	for(int i = 0; i < n; i++) {
		visited[i] = true;
		DFS_Stack((i==0)?1:0, a, n, visited);
		if(!CheckConnection(visited, n))
			cout << i+1 << ' ';
		memset(visited, false, n);
	}
	cout << endl;
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
			a[begin-1][end-1] = 1;
			a[end-1][begin-1] = 1;
		}
		ArticurationPoint(a, v, visited);
	}
}

