#include <bits/stdc++.h>
using namespace std;


int BFS(int s, int v, vector<int> *list, bool *visited) {
	queue<int> queue; queue.push(s);
	visited[s] = true;
	int t = 1;
	while(!queue.empty() ) {
		s = queue.front(); queue.pop();
		for(int i = 0; i < list[s].size(); i++) {
			if(!visited[list[s][i]]) {
				t = t + 1;
				queue.push(list[s][i]);
				visited[list[s][i]] = true;
			}
		}
	}
	return t;
}

int count(int v, vector<int> *list, bool *visited) {
	int ma = 0;
	for(int  i = 0; i < v; i++) {
		if(!visited[i]) {
			int t = BFS(i, v, list, visited);
			ma = (ma < t)?t:ma;
		}
	}
	return ma;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int v, e; cin >> v >> e;
		vector<int> list[v];
		bool visited[v] = {};
		for(int i = 0; i < e; i++) {
			int begin, end; cin >> begin >> end;
			list[begin-1].push_back(end-1);
			list[end-1].push_back(begin-1);
		}
		cout << count(v, list, visited) << endl;
	}
}
