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

void BFS_queue(int u, int n, vector<vector<int> > list, 
		bool *visited, vector<edge> &res) {
	queue<int> queue; queue.push(u);
	visited[u] = true;
	while(!queue.empty()) {
		u = queue.front();
		queue.pop();
		for(int i = 0; i < list[u].size(); i++) {
			if(!visited[list[u][i]]) {
				visited[list[u][i]] = true;
				edge ed = {u, list[u][i]};
				res.push_back(ed);
				queue.push(list[u][i]);
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
		BFS_queue(u-1, v, list, visited, res);
		showResult(res, v);
	}
}

