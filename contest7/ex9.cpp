#include <bits/stdc++.h>
using namespace std;

struct bracket{
	int x;
	int y;
};

bool Less(bracket a, bracket b) {
	return a.x < b.x;
}

void generateNext(int *a, int n, bool &isOk) {
	int i = n-1;
	while(a[i] == 1 && i >= 0) {
		a[i] = 0;
		i = i - 1;
	}
	if(i >= 0)
		a[i] = 1;
	else isOk = true;
	
}

string print(string str, vector<bracket> b, int *a, int n) {
	for(int i = 0; i < n ; i++) {
		if(a[i] == 1) {
			str[b[i].x] = '&';
			str[b[i].y] = '&';
		}
	}
	for(int i = str.size()-1; i >= 0; i--)
		if(str[i] == '&')
			str.erase(str.begin()+i);
	return str;
}

void solve(string str) {
	vector<bracket> b;
	stack<int> s;
	
	for(int i = 0; i < str.size(); i++) {
		if(str[i] == '(')
			s.push(i);
		else if(str[i] == ')') {
			bracket t = {s.top(), i};
			b.push_back(t);
			s.pop();
		}
	}
	sort(b.begin(), b.end(), Less);

	int n = b.size(), a[n] = {};
	vector<string> ans, result;
	bool isOk = false;
	a[n-1] = 1;
	
	while(!isOk) {
		ans.push_back(print(str, b, a, n));
		generateNext(a, n, isOk);
	}
	
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++) {
		if(result.size() == 0)
			result.push_back(ans[i]);
		else if(ans[i] != result[result.size()-1])
			result.push_back(ans[i]);
	}
	
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
}

int main() {
	string str; cin >> str;
	solve(str);
}
