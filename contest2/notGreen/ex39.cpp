#include <iostream>
using namespace std;

int main() {
	int k;
	string s; cin >> s >> k;
	while(s.length() < k) {
		s = s + s[s.length()-1];
		s = s + s.substr(0, s.length()-2);
	}
	cout << s[k-1];
}
