#include <iostream>
using namespace std;

bool check(char *s, int n, int k) {
	int c = 0; int i = 0;
	while(i < n) {
		int d = 0;
		while(s[i] == 'A' && i < n)
			d++, i++;
		if(d > k)
			return false;
		if(d == k)
			c++;
		i++;
	}
	if(c == 1)
		return true;
	return false;
}

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
	int n, k; cin >> n >> k;
	char *s = new char[n];
	bool isok = false;
		string res = "";
		int t = 0;
	generateFirst(s, n);
	while(!isok) {
		if(check(s, n, k)) {
			t = t + 1;
			res += s;
			res += '\n';
		}
		generateNext(s, n, isok);
	}
	cout << t << '\n' << res;
}
