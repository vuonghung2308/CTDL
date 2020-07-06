#include <bits/stdc++.h>
using namespace std;

bool BFS_Queue(int start, int **a, int n, int target) {
	bool visited[n] = {};
	visited[start] = true;
	queue<int> queue;
	queue.push(start);
	while(!queue.empty()) {
		start = queue.front(); queue.pop();
		if(start == target) return true;
		for(int i = 0; i < n; i++) {
			if(a[start][i] == 1 && !visited[i]) {
				if(i == target) return true;
				visited[i] = true;
				queue.push(i);
			}
		}
	}
	return false;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int v, e, start, target;
		cin >> v >> e;
		int **a = new int*[v];
		for(int i = 0; i < v; i++)
			a[i] = new int[v];
		for(int i = 0; i < e; i++) {
			int begin, end; 
			cin >> begin >> end;
			if(begin <= v && begin >= 0 && end >= 0 && end <= v) {
				a[begin-1][end-1] = 1;
				a[end-1][begin-1] = 1;
			}
		}
		int q; cin >> q;
		for(int i = 0; i < q; i++) {
			cin >> start >> target;
			if(BFS_Queue(start-1, a, v, target-1))
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
}

