#include <bits/stdc++.h>
using namespace std;

void toVector(string s, vector<int> &list) {
	for(int i = 0; i < s.size(); i++) {
		int d = 0;
		while(isdigit(s[i]) ) {
			d = d * 10 + s[i] - '0';
			i = i + 1;
		}
		list.push_back(d);
	}
}

void convert(vector<vector<int> > list) {
	int n = list.size();
	for(int i = 0; i < n; i++)
		for(int j = 0; j < list[i].size(); j++)
			if(list[i][j] > i)
				cout << i+1 << ' ' << list[i][j] << endl;
}

int main() {
	int n; cin >> n; cin.ignore();
	vector<vector<int> > list(n, vector<int>());
	for(int i = 0; i < n; i++) {
		string s = ""; 
		while(s == "")
			getline(cin, s);
		toVector(s, list[i]);
	}
	convert(list);
}
