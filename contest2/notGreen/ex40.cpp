#include <bits/stdc++.h>
using namespace std;

void Try(int i, int n, int &f, int sum, int min, int *res, int **a, bool *visited) {
	for(int j = 0; j < n; j++) {
		if(!visited[j]) {
			visited[j] = true;
			res[i] = j;
			sum = sum+a[res[i-1]][j];
			int g = sum + (n-i)*min;
			if(i == n-1)
				f = (f <(sum+a[j][0]))?f:(sum+a[j][0]);
			else if(i < n-1 && g < f) Try(i+1, n, f, sum, min, res, a, visited);
			visited[j] = false;
			sum = sum-a[res[i-1]][j];
		}
	}
}

int main() {
	int n, min = INT_MAX, f = INT_MAX; cin >> n;
	int *res = new int[n];
	int **a = new int*[n];
	bool visited[n] = {false};
	for(int i = 0; i < n; i++) {
		a[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			if(a[i][j] != 0) min = (min < a[i][j])?min:a[i][j];
		}
	}
	visited[0] = true;
	res[0] = 0;
	Try(1, n, f, 0, min, res, a, visited);
	cout << f;
}


