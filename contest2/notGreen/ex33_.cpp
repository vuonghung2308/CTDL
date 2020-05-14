#include <bits/stdc++.h>
using namespace std;

void Try(int i, int n, bool *cot, bool *dcx, bool *dcn, int &count) {
	for(int j = 0; j < n; j++) {
		if(!cot[j] && !dcx[i+j] && !dcn[n-1-i+j]) {
			cot[j] = true;
			dcx[i+j] = true;
			dcn[n-1-i+j] = true;
			if(i == n-1)
				count ++;
			else Try(i+1, n, cot, dcx, dcn, count);
			cot[j] = false;
			dcx[i+j] = false;
			dcn[n-1-i+j] = false;
		}
	}
}

int main() {
	int n, count = 0; cin >> n;
	bool cot[n] = {false};
	bool duongcheox[2*n-1] = {false};
	bool duongcheon[2*n-1] = {false};
	Try(0, n, cot, duongcheox, duongcheon, count);
	cout << count << endl;
}
