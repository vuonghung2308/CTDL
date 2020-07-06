#include <bits/stdc++.h>
using namespace std;

bool DFS(int s, int v, vector<vector<int> > list, bool *visited, bool *check) {
	vector<int> previous(v, -1);
	stack<int> stack; stack.push(s);
	visited[s] = true;
	while(!stack.empty() ) {
		s = stack.top(); stack.pop();
		
		for(int i = 0; i < list[s].size(); i++) {
			if(visited[list[s][i]] == false) {
				visited[list[s][i]] = true;
				previous[list[s][i]] = s;
				stack.push(s);
				stack.push(list[s][i]);
			} else if(previous[s] != list[s][i] 
					&& previous[list[s][i]] != s)
				return true;
		}
	}
	return false;
}

bool hasCycle(int v, vector<vector<int> > list) {
	bool visited[v] = {};
	bool check[v] = {};
	for(int i = 0; i < v; i++) {
		if(!visited[i] && DFS(i, v, list, visited, check))
			return true;
	}
	return false;
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
		if(hasCycle(v, list) )
			cout << "YES\n";
		else cout << "NO\n";
	}
}
