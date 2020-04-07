#include <iostream>
#include <string.h>
using namespace std;

void generateNext(char *s) {
	int i = strlen(s) - 1;
	while(i >= 0 && s[i] == '1')
		s[i] = '0', i--;
	if(i >= 0)
		s[i] = '1';
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		char s[1000] = {""};
		cin >> s;
		generateNext(s);
		cout << s << endl;
	}
}
