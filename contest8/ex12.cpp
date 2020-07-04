#include <bits/stdc++.h>
using namespace std;

int solve(set<string> Dictionary, string start, string target) {
	queue<string> Q; Q.push(start);
	int level = 0, wordlength = start.size();
	while(!Q.empty()) {
		int x = Q.size(); ++level;
		for(int i = 0; i < x; i++) {
			string word = Q.front(); Q.pop();
			if(word == target) return level;
			for(int pos = 0; pos < wordlength; pos++) {
				char origin = word[pos];
				for(char c = 'A'; c <= 'Z'; c++) {
					word[pos] = c;
					if(word == target)
						return level + 1;
					if(Dictionary.find(word) == Dictionary.end())
						continue;
					Q.push(word);
					Dictionary.erase(word);
				}
				word[pos] = origin;
			}
		}
	}
	return 0;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		string start, target;
		int n; cin >> n >> start >> target;
		set<string> Dictionary;
		for(int i = 0; i < n; i++) {
			string temp; cin >> temp;
			if(temp == start) continue;
			Dictionary.insert(temp);
		}
		cout << solve(Dictionary, start, target) << endl;
	}
}
