#include <bits/stdc++.h>
using namespace std;

int find(int *a, int n, int x) {
	for(int i = 0; i < n; i++)
		if(x == a[i])
			return i;
	return -1;
}

void postorder(int n, int *ino, int *pre) {
	int i = find(ino, n, pre[0]);
	if(i != 0) postorder(i, ino, pre+1);
	if(i != n-1) postorder(n-1-i, ino+i+1, pre+i+1);
	cout << pre[0] << ' ';
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int ino[n], pre[n];
		for(int i = 0; i < n; i++)
			cin >> ino[i];
		for(int i = 0; i < n; i++)
			cin >> pre[i];
		postorder(n, ino, pre);
		cout << endl;
	}
}
