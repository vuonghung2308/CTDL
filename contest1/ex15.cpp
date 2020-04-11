#include <iostream>
#include <string.h>
using namespace std;

void swap(int &a, int &b) {
	int x = a; a = b; a = x;
}

void generateNext(char *a) {
	int i = strlen(a) - 2;
	while(a[i] >= a[i+1])
		i--;
	if(i > 0) {
		int t = strlen(a)-1;
		while(a[t] <= a[i])
			t--;
		swap(a[t], a[i]);
		int b = i+1, e = strlen(a)-1;
		while(b < e) {
			swap(a[b], a[e]);
			b++; e--;
		}
	} else strcpy(a, "BIGGEST");
}

int main() {
	int t; cin >> t;
	char **res;
	res = new char*[t+5];
	for(int i = 0; i < t; i++) {
		res[i] = new char[100];
		int n; cin >> n >> res[i];
		generateNext(res[i]);
	}
	for(int i = 0; i < t; i++)
		cout << i+1 << " " << res[i] << endl;
}
