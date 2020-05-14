#include <bits/stdc++.h>
using namespace std;


bool isOk(int x, int y, int n, int **a, bool **visited) {
	return x >= 0 && x < n && y >= 0 && y < n && a[x][y] == 1 && !visited[x][y];
}

void Try(int x, int y, int n, int **a, bool **visited, string res, vector<string> &result, int move[][2]) {
	if(x == n-1 && y == n-1)
		result.push_back(res);
	else {
		for(int i = 0; i < 4; i++) {
			if(isOk(x+move[i][0], y+move[i][1], n, a, visited)) {
				visited[x+move[i][0]][y+move[i][1]] = true;
				switch(i) {
					case 0: {
						res.push_back('D');
						break;
					}
					case 1: {
						res.push_back('R');
						break;
					}
					case 2: {
						res.push_back('L');
						break;
					}
					case 3: {
						res.push_back('U');
						break;
					}
				}
				Try(x+move[i][0], y+move[i][1], n, a, visited, res, result, move);
				visited[x+move[i][0]][y+move[i][1]] = false;
				res.erase(res.end()-1);			
			}	
		}
	}
}

void showResult(vector<string> result) {
	if(result.size() == 0)
		cout << -1 << endl;
	else
		for(int i = 0; i < result.size(); i++)
			cout << result[i] << ' ';
	cout << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		
	int move[][2] = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };
	int **a, n;
	bool **visited;
	vector<string> result;
	string res;
	cin >> n;
	a = new int*[n];
	visited = new bool*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[n];
		visited[i] = new bool[n];
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			visited[i][j] = false;
		}
	}
	visited[0][0] = true;
	Try(0, 0, n, a, visited, res, result, move);
	showResult(result);
	}
}
