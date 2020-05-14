#include <iostream>
using namespace std;

void show(int **a, int n, bool &has) {
	has = true;
	cout << '[';
	for(int i = 0; i < n; i++)
		for(int j = 0; j < a[i][1]; j++)
			cout << a[i][0] << ' ';
	cout << "\b] ";
}

void Try(int i, int n, int s, int sum, bool &has, int **a) {
	for(int j = i; j < n; j++) {
		if(sum+a[j][0] <= s) {
			a[j][1]++;
			if(sum+a[j][0] == s)
				show(a, n, has);
			else if(sum+a[j][0] < s)
				Try(j, n, s, sum+a[j][0], has, a);
			a[j][1]--;
		}
	}
}


int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, s; cin >> n >> s;
		int **a = new int*[n];
		bool has = false;
		for(int i = 0; i < n; i++) {
			a[i] = new int[2];
			a[i][1] = 0;
			cin >> a[i][0];
		}
		Try(0, n, s, 0, has, a);
		if(has)
			cout << endl;
		else cout << "-1" << endl;
	}
}
