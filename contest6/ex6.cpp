#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 0; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, n0 = 0, n1 = 0, n2 = 0;
		cin >> n;
		for(int i = 0; i < n; i++) {
			int t; cin >> t;
			if(t == 0) n0 = n0 + 1;
			else if(t == 1) n1 = n1 + 1;
			else n2 = n2 + 1;
		}
		for(int i = 0; i < n0; i++)
			cout << 0 << ' ';
		for(int i = 0; i < n1; i++)
			cout << 1 << ' ';
		for(int i = 0; i < n2; i++)
			cout << 2 << ' ';
		cout << endl;
	}
}
