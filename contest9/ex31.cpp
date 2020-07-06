#include <bits/stdc++.h>
using namespace std;

bool DFS(int s, int v, vector<vector<int> > list, bool *visited) {
	vector<int> previous(v, -1);
	queue<int> queue; queue.push(s);
	visited[s] = true;
	while(!queue.empty() ) {
		s = queue.front(); queue.pop();
		
		for(int i = 0; i < list[s].size(); i++) {
			if(visited[list[s][i]] == false) {
				visited[list[s][i]] = true;
				previous[list[s][i]] = s;
				queue.push(list[s][i]);
			} else if(previous[s] != list[s][i] )
				return true;
		}
	}
	return false;
}

bool hasCycle(int v, vector<vector<int> > list) {
	bool visited[v] = {};
	for(int i = 0; i < v; i++) {
		if(!visited[i] && DFS(i, v, list, visited))
			return true;
	}
	return false;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int v, e; cin >> v;
		vector<vector<int> > list(v, vector<int>());
		for(int i = 0; i < v-1; i++) {
			int begin, end; cin >> begin >> end;
			list[begin-1].push_back(end-1);
			list[end-1].push_back(begin-1);
		}
		if(hasCycle(v, list) )
			cout << "NO\n";
		else cout << "YES\n";
	}
}
