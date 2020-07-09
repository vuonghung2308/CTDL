#include <bits/stdc++.h>
using namespace std;

struct edge{
	int u; 
	int v;
	int c;
};

int Find(int i, int *parent) {
	while(parent[i] >= 0)
		i = parent[i];
	return i;
}

int Connect(int u, int v, int *parent) {
	if(parent[u] > parent[v]) {
		parent[v] = parent[u] + parent[v];
		parent[u] = v;		
	} else {
		parent[u] = parent[v] + parent[u];
		parent[v] = u;
	}
}

bool Less(edge a, edge b) {
	return a.c < b.c;
}

int Kruskal(int v, int e, edge *list, int *parent) {
	int min = 0, nt = 0;
	sort(list, list+e, Less);
	for(int i = 0; i < e; i++) {
		if(nt == v-1) break;
		int x = Find(list[i].u, parent);
		int y = Find(list[i].v, parent);
		if(x != y) {
			min = min + list[i].c;
			Connect(x, y, parent);
			nt = nt + 1;
		}
	}
	return min;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int v, e; cin >> v >> e;
		edge *list = new edge[e];
		int *parent = new int[v];
		for(int i = 0; i < v; i++)
			parent[i] = -1;
		for(int i = 0; i < e; i++) {
			int u, v, c; cin >> u >> v >> c;
			edge t = {u-1, v-1, c};
			list[i] = t;
		}
		cout << Kruskal(v, e, list, parent) << endl;
	}
}
