#include <bits/stdc++.h>
using namespace std;

struct point{
	int x;
	int y;
	int step;
};

bool isOne(point x, point y) {
	return x.x == y.x && x.y == y.y;
}

int solve(char **a, int n, point start, point target) {
	start.step = 0;
	queue<point> Q; Q.push(start);
	bool visited[n][n] = {};
	while(!Q.empty() ) {
		point x = Q.front(); Q.pop();
		if(isOne(x, target) ) return x.step;
		
		for(int i = x.x+1; i < n && a[i][x.y] == '.'; i++) {
			point t = {i, x.y, x.step+1};
			if(isOne(t, target) )
				return t.step;
			if(!visited[t.x][t.y]) {
				visited[t.x][t.y] = true;
				Q.push(t); 
			}
		}
		
		for(int i = x.x-1; i >= 0 && a[i][x.y] == '.'; i--) {
			point t = {i, x.y, x.step+1};
			if(isOne(t, target) )
				return t.step;
			if(!visited[t.x][t.y]) {
				visited[t.x][t.y] = true;
				Q.push(t); 
			}
		} 
		
		for(int i = x.y+1; i < n && a[x.x][i] == '.'; i++) {
			point t = {x.x, i, x.step+1};
			if(isOne(t, target) )
				return t.step;
			if(!visited[t.x][t.y]) {
				visited[t.x][t.y] = true;
				Q.push(t); 
			}
		} 
		
		for(int i = x.y-1; i >= 0 && a[x.x][i] == '.'; i--) {
			point t = {x.x, i, x.step+1};
			if(isOne(t, target) )
				return t.step;
			if(!visited[t.x][t.y]) {
				visited[t.x][t.y] = true;
				Q.push(t); 
			}
		} 
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		char **a = new char*[n];
		point target, start;
		for(int i = 0; i < n; i++) {
			a[i] = new char[n];
			for(int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		cin >> start.x >> start.y >> target.x >> target.y;
		cout << solve(a, n, start, target) << endl;
	}
}
