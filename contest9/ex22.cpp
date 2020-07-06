#include <bits/stdc++.h>
using namespace std;

bool Connected(int v, bool *visited) {
	for(int i = 0; i < v; i++)
		if(visited[i] == false)
			return false;
	return true;
}

void BFS(int s, int v, vector<vector<int> > list,
		bool *visited, int e1, int e2) {
	queue<int> queue; queue.push(s);
	visited[s] = true;
	while(!queue.empty() ) {
		s = queue.front(); queue.pop();
		for(int i = 0; i < list[s].size(); i++) {
			if( (s == e1 && list[s][i] == e2) 
					|| (s == e2 && list[s][i] == e1) )
				continue;
			if(visited[list[s][i]] == false) {
				visited[list[s][i]] = true;
				queue.push(list[s][i]);
			}
		}
	}
	
}

bool isArticurationEdge(int v, int e1, int e2, 
		vector<vector<int> > list) {
	bool visited[v] = {};
	BFS(0, v, list, visited, e1, e2);
	return !Connected(v, visited);	
}

void solve(int v, vector<vector<int> > list) {
	for(int i = 0; i < v; i++) {
		for(int j = 0; j < list[i].size(); j++) {
			if(i < list[i][j] && 
				isArticurationEdge(v, i, list[i][j], list))
			cout << i+1 << ' ' << list[i][j]+1 << ' ';
		}
	}
	cout << endl;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int v, e; cin >> v >> e;
		vector<vector<int> > list(v, vector<int>());
		for(int i = 0; i < e; i++) {
			int begin, end; cin >> begin >> end;
			list[begin-1].push_back(end-1);
			list[end-1].push_back(begin-1);
		}
		solve(v, list);
	}
}
