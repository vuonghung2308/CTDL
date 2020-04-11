#include <iostream>
using namespace std;

bool check(char *s, int n, int k) {
	int t = 0;
	for(int i = 0; i < n; i++)
		t = t + s[i] - '0';
	if(t == k)
		return true;
	return false;
}

void generateFirst(char *s, int n) {
	for(int i = 0; i < n; i++)
		s[i] = '0';
	s[n] = '\0';
}

void generateNext(char *s, int n, bool &isok) {
	int i = n - 1;
	while(s[i] == '1')
		s[i] = '0', i--;
	if(i >= 0)
		s[i] = '1';
	else isok = true;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, k; cin >> n >> k;
		char *s = new char[n];
		bool isok = false;
		generateFirst(s, n);
		while(!isok) {
			if(check(s, n, k))
				cout << s << endl;
			generateNext(s, n, isok);
		}
	}
}
