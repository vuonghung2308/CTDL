#include <iostream>
using namespace std;

void generateFirst(char *s, int n) {
	for(int i = 0; i < n; i++)
		s[i] = 'A';
	s[n] = '\0';
}

void generateNext(char *s, int n, bool &isok) {
	int i = n - 1;
	while(s[i] == 'B')
		s[i] = 'A', i--;
	if(i >= 0)
		s[i] = 'B';
	else isok = true;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		char *s = new char[n];
		bool isok = false;
		generateFirst(s, n);
		while(!isok) {
			cout << s << ' ';
			generateNext(s, n, isok);
		}
		cout << endl;
	}
}
