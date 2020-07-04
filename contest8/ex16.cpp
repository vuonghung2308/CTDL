#include <bits/stdc++.h>
using namespace std;

void rotate1(vector<vector<int> > &a) {
	int t = a[0][0];
	a[0][0] = a[1][0];
	a[1][0] = a[1][1];
	a[1][1] = a[0][1];
	a[0][1] = t;
}

void rotate2(vector<vector<int> > &a) {
	int t = a[0][1];
	a[0][1] = a[1][1];
	a[1][1] = a[1][2];
	a[1][2] = a[0][2];
	a[0][2] = t;
}

int solve(vector<vector<int> > start, vector<vector<int> > target) {
	queue<vector<vector<int> > > Q; Q.push(start);
	set<vector<vector<int> > > S; S.insert(start);
	int level = 0;
	while(!Q.empty()) {
		int size = Q.size();
		for(int i = 0; i < size; i++) {
			vector<vector<int> > temp = Q.front();
			Q.pop();
			if(temp == target) return level;
			vector<vector<int> > rot1 = temp, rot2 = temp;
			rotate1(rot1); rotate2(rot2);
			if(rot1 == target || rot2 == target)
				return level + 1;
			if(S.find(rot1) == S.end()) {
				S.insert(rot1);
				Q.push(rot1);
			}
			if(S.find(rot2) == S.end()) {
				S.insert(rot2);
				Q.push(rot2);
			}
		}
		level = level + 1;
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		vector<vector<int> > start(2, vector<int>(3, 0));
		vector<vector<int> > target(2, vector<int>(3, 0));
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 3; j++)
				cin >> start[i][j];
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 3; j++)
				cin >> target[i][j];
		cout << solve(start, target) << endl;
	}
}
