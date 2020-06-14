#include <bits/stdc++.h>
using namespace std;

bool check(int n, int *res, int x) {
	if(n == 0)
		return true;
	for(int i = 0; i < n; i++) {
		int t = n - i;
		if(res[i]-t == x || res[i]+t == x)
			return false;
	}
	return true;
}

void Try(int i, int n, int *res, bool *visited, int &count) {
	for(int j = 0; j < n; j++) {
		if(visited[j] == false && check(i, res, j)) {
			visited[j] = true;
			res[i] = j;
			if(i == n-1)
				count ++;
			else Try(i+1, n, res, visited, count);
			visited[j] = false;
		}
	}
}

int main() {
	int n, count = 0; cin >> n;
	int *res = new int[n];
	bool visited[n] = {false};
	Try(0, n, res, visited, count);
	cout << count;
}
