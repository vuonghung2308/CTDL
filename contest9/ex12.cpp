#include <bits/stdc++.h>
using namespace std;

void BFS_Queue(int v, int **a, int n, bool *visited, int *previous) {
	queue<int> queue;
	queue.push(v);
	visited[v] = true;
	while(!queue.empty()) {
		v = queue.front();
		queue.pop();
		for(int i =0; i < n; i++) {
			if(a[v][i] == 1 && !visited[i]) {
				visited[i] = true;
				previous[i] = v;
				queue.push(i);
			}
		}
	}
}

void ShowWay(int s, int t, int *previous) {
	vector<int> w;
	if(previous[t] == -1) {
		cout << -1 << endl;
	} else {
		w.push_back(t+1);
		while(t != s) {
			t = previous[t];
			w.push_back(t+1);
		}
		for(int i = w.size()-1; i >= 0; i--)
			cout << w[i] << ' ';
		cout << endl;
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int v, e, start, target;
		cin >> v >> e >> start >> target;
		bool visited[v] = {};
		int previous[v] = {};;
		int **a = new int*[v];
		for(int i = 0; i < v; i++) {
			a[i] = new int[v];
			previous[i] = -1;
		}
		for(int i = 0; i < e; i++) {
			int start, end; cin >> start >> end;
			a[start-1][end-1] = 1;
			a[end-1][start-1] = 1;
		}
		BFS_Queue(start-1, a, v, visited, previous);
		ShowWay(start-1, target-1, previous); 
	}
}

