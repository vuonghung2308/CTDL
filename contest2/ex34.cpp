#include <iostream>
using namespace std;

void Try(int i, int n, int **a, bool *cot, bool *dcx, bool *dcn, int &res, int sum) {
	for(int j = 0; j < n; j++) {
		if(!cot[j] && !dcx[i+j] && !dcn[n-1-i+j]) {
			cot[j] = true;
			dcx[i+j] = true;
			dcn[n-1-i+j] = true;
			if(i == n-1)
				res = ((sum +a[i][j]) > res)?(sum +a[i][j]):res;
			else Try(i+1, n, a, cot, dcx, dcn, res, sum+a[i][j]);
			cot[j] = false;
			dcx[i+j] = false;
			dcn[n-1-i+j] = false;
		}
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int **a = new int*[8];
		int result = 0;
		bool cot[8] = {false}, dcx[17] = {false}, dcn[17] = {false};
		for(int i = 0; i < 8; i++) {
			a[i] = new int[8];
			for(int j = 0; j < 8; j++)
				cin >> a[i][j];
		}
		Try(0, 8, a, cot, dcx, dcn, result, 0);
		cout << result << endl;
	}
}
