#include <iostream>
#include <string>
using namespace std;

void generateNext(string &s) {
	int i = s.length() - 1;
	while(i >= 0 && s[i] == '1')
		s[i] = '0', i--;
	if(i >= 0)
		s[i] = '1';
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s; cin >> s;
		generateNext(s);
		cout << s << endl;
	}
}
