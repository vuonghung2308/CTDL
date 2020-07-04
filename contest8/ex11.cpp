#include <bits/stdc++.h>
using namespace std;

bool sont(string str) {
	int t = (str[0] - '0')*1000 + (str[1] - '0')*100 
			+ (str[2] - '0')*10 + (str[3] - '0');
	if(t <= 2) return true;
	for(int i = 2; i*i <= t; i++)
		if(t%i == 0)
			return false;
	return true;
}

int solve(string str1, string str2) {
	queue<string> q; q.push(str1);
	queue<int> c; c.push(0);
	set<string> s; s.insert(str1);
	
	while(!q.empty()) {
		string str = q.front(); q.pop();
		int count = c.front(); c.pop();
		if(str == str2) return count;
		
		for(int i = 3; i >= 0; i--) {
			int t = (i == 0)?'1':'0';
			int t1 = str[i];
			for(int j = t; j <= '9'; j++){
				if(j == t1) continue;
				str[i] = j;
				if(sont(str)) {
					if(str == str2) {
						return count + 1;
					}
					else if(s.find(str) == s.end()) {
						q.push(str);
						c.push(count+1);
						s.insert(str);
					}
				}
			}
			str[i] = t1;
		}
	}
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string str1, str2; cin >> str1 >> str2;
		cout << solve(str1, str2) << endl;
	}
}
