#include <bits/stdc++.h>
using namespace std;

struct point{
	int x;
	int y;
};

point way1(point x, int **a) {
	point res = {x.x, x.y + a[x.x][x.y]};
	return res;
}

point way2(point x, int **a) {
	point res = {x.x + a[x.x][x.y], x.y};
	return res;
}

bool isOk(point x, point target) {
	return x.x >= 0 && x.y >= 0 && x.x <= target.x 
		&& x.y <= target.y;
}

bool isEqual(point x, point y) {
	return x.x == y.x && x.y == y.y;
}


int solve(int **a, int n, int m) {
	point start = {0, 0}, target = {n-1, m-1};
	queue<point> Q; Q.push(start);
	int visited[n][m] = {};
	visited[0][0] = true;
	int level = 0;
	while(!Q.empty()) {
		int size = Q.size();
		for(int s = 0; s < size; s++) {
			point p = Q.front(); Q.pop();
			point p1 = way1(p, a);
			point p2 = way2(p, a);
			if(isEqual(p, target) == true) return level;
			if(isEqual(p1, target) || isEqual(p2, target))
				return level + 1;
			if(isOk(p1, target) && !visited[p1.x][p1.y]) {
				visited[p1.x][p1.y] = true;
				Q.push(p1);
			}
			if(isOk(p2, target) && !visited[p2.x][p2.y]) {
				visited[p2.x][p2.y] = true;
				Q.push(p2);
			}
		}
		level = level + 1;
	}
	return -1;
}

int main() {
	int t; cin >> t;
	for(int z = 0; z < t; z++) {
		int n, m; cin >> n >> m;
		int **a = new int*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[m];
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		}
		cout << solve(a, n, m) << endl;
	}
}
