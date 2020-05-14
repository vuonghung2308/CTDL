#include <bits/stdc++.h>
using namespace std;

void Try(int i, int n, int sum, int s, bool &has, int *a, bool *visited) {
	for(int j = 0; j < n; j++) {
		if(!visited[j] && sum+a[j] <= s) {
			visited[j] = true;
			if(sum+a[j] < s)
				Try(i+1, n, sum+a[j], s, has, a, visited);
			else if(sum+a[j] == s) {
				if(i == n-1) 
					has = true;
				else Try(i+1, n, 0, s, has, a, visited);
			}
			visited[j] = false;
		}
		if(has)
			break;
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, k, sum = 0; cin >> n >> k;
		bool has = false;
		int *a = new int[n];
		bool *visited = new bool[n];
		memset(visited, false, n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if(sum%k == 0) Try(0, n, 0, sum/k, has, a, visited);
		if(has)
			cout << 1 << endl;
		else cout << 0 << endl;
	}
}
