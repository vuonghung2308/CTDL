#include <bits/stdc++.h>
using namespace std;

struct edge{
	int u;
	int v;
};

void showResult(vector<edge> res, int n) {
	if(res.size() == n-1) {
		for(int i = 0; i < res.size(); i++)
			cout << res[i].u+1 << ' ' << res[i].v+1 << endl;
	} else cout << -1 << endl;
}

void DFS_Stack(int u, int n, vector<vector<int> > list, 
		bool *visited, vector<edge> &res) {
	stack<int> stack;
	stack.push(u);
	visited[u] = true;
	while(!stack.empty()) {
		u = stack.top();
		stack.pop();
		for(int i = 0; i < list[u].size(); i++) {
			if(!visited[list[u][i]]) {
				visited[list[u][i]] = true;
				edge ed = {u, list[u][i]};
				res.push_back(ed);
				stack.push(u);
				stack.push(list[u][i]);
				break;
			}
		}
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int v, e, u; cin >> v >> e >> u;
		vector<vector<int> > list(v, vector<int>());
		bool visited[v] = {};
		vector<edge> res;
		for(int  i = 0; i < e; i++) {
			int begin, end; cin >> begin >> end;
			if(begin <= v && begin >=0 && end <= v && end >= 0) {
				list[begin-1].push_back(end-1);
				list[end-1].push_back(begin-1);
			}
		}
		DFS_Stack(u-1, v, list, visited, res);
		showResult(res, v);
	}
}

