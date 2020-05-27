#include <iostream>
using namespace std;

int greedy(string s) {
	int n = 0, d = 0, i = 0;
	while(i < s.size()) {
		if(s[i] == '[')
			d++;
		else d--;
		if(d < 0) {
			while(s[i] == s[i+1] && i < s.size())
				i = i + 1;
			swap(s[i], s[i+1]);
			n = n + 1;
			i = -1;
			d = 0;
		}
		i++;
	}
	return n;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {	
		string s; cin >> s;
		cout << greedy(s) << endl;
	}
}
