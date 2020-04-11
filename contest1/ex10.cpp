#include <iostream>
#include <string>
using namespace std;

void binarytogray(string &s) {
	for(int i = s.size()-2; i >= 0; i--)
		if(s[i] == '1')
			s[i+1] = (s[i+1] == '1')?'0':'1';
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s; cin >> s;
		binarytogray(s);
		cout << s << endl;
	}
}
