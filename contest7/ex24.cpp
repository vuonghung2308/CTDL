#include <bits/stdc++.h>
using namespace std;

struct expression {
	int factor;
	int degree;
};

vector<expression> read(void) {
	vector<expression> ex;
	string str = "";
	while(str == "") getline(cin, str);
	expression temp;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] == '+') {
			ex.push_back(temp);
		} else if(isdigit(str[i])) {
			int t = 0;
			while(isdigit(str[i])) {
				t = t * 10 + str[i] - '0';
				i = i + 1;
			}
			if(str[i] == '*') temp.factor = t;
			else temp.degree = t;
			i = i - 1;
		}
	}
	ex.push_back(temp);
	return ex;
}

void solve(vector<expression> ex1, vector<expression> ex2) {
	int i = 0, j = 0;
	int n1 = ex1.size(), n2 = ex2.size();
	vector<expression> res;
	while(i < n1 && j < n2) {
		if(ex1[i].degree == ex2[j].degree) {
			ex1[i].factor += ex2[j].factor;
			res.push_back(ex1[i]);
			i = i + 1; j = j + 1;
		} else if(ex1[i].degree > ex2[j].degree) {
			res.push_back(ex1[i]);
			i = i + 1;
		} else {
			res.push_back(ex2[j]);
			j = j + 1;
		}
	}
	while(i < n1) { res.push_back(ex1[i++]); }
	while(j < n2) { res.push_back(ex2[j++]); }
	for(int i = 0; i < res.size()-1; i++)
		cout << res[i].factor << '*' << "x^" << res[i].degree << " + ";
	cout << res[res.size()-1].factor << '*' << "x^" << res[res.size()-1].degree << "\n";
}

int main() {
	int t; cin >> t;
	cin.ignore();
	for(int i = 0; i < t; i++) {
		vector<expression> ex1 = read();
		vector<expression> ex2 = read();
		solve(ex1, ex2);
	}
}
