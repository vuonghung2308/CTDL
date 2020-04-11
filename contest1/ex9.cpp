#include <iostream>
using namespace std;

void generateGray1(char *s, int n) {
	char a[n] = {'\0'};
	for(int i = 0; i < n; i++)
		a[i] = s[i];
	a[n] = '\0';
	for(int i = n-2; i >= 0; i--)
		if(a[i] == '1')
			a[i+1] = (a[i+1] == '0')?'1':'0';
	cout << a << ' ';
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
		int n; cin >> n;
		char *s = new char[n];
		bool isok = false;
		generateFirst(s, n);
		while(!isok) {
			generateGray1(s, n);
			generateNext(s, n, isok);
		}
		cout << endl;
	}
}

