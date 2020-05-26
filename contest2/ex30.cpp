#include <bits/stdc++.h>
using namespace std;


bool Prime(int x) {
	if(x < 2)
		return false;
	else 
		for(int i = 2; i*i <= x; i++)
			if(x%i == 0)
				return false;
	return true;
}

void addResult(int *res, int n, vector<vector<int> > &result) {
	result.push_back(vector<int>(res, res+n));
}

void showResult(vector<vector<int> > result) {
	cout << result.size() << endl;
	if(result.size()!=0) {
		for(int i = 0; i < result.size(); i++) {
			for(int j = 0; j < result[i].size(); j++)
				cout << result[i][j] << ' ';
			cout << endl;
		}
	}
}

void Try(int i, int n, int p, int s, int *res, vector<vector<int> > &result) {
	for(int j = p+1; j <= s; j++) {
		if(Prime(j)) {
			res[i] = j;
			if(i==n-1 && s-j == 0) 
				addResult(res, n, result);
			else Try(i+1, n, j, s-j, res, result);
		}
	}
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, p, s; cin >> n >> p >> s;
		vector<vector<int> > result;
		int res[n] = {0};
		Try(0, n, p, s, res, result);
		showResult(result);
	}
}
