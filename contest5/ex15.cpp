#include <iostream>
using namespace std;

int solve(string s1, string s2, string s3, int n1, int n2, int n3) {
	int a[n1+1][n2+1][n3+1] = {};
	for(int x = 1; x <= n1; x++) {
		for(int y = 1; y <= n2; y++)
			for(int z = 1; z <= n3; z++)
				if(s1[x-1] == s2[y-1] && s2[y-1] == s3[z-1])
					a[x][y][z] = a[x-1][y-1][z-1] + 1;
				else a[x][y][z] = max(a[x-1][y][z], max(a[x][y-1][z], a[x][y][z-1]));
	}
	return a[n1][n2][n3];
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s1, s2, s3;
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		cin >> s1 >> s2 >> s3;
		cout << solve(s1, s2, s3, n1, n2, n3) << endl;
	}
}
