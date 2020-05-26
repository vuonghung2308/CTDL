#include <bits/stdc++.h>
#define MAX 20
using namespace std;

long long valueOf(int *a) {
	long long value = 0;
	for(int i = 0; i < MAX; i++) 
		value = (long long) value*10 + a[i];
	return value;
}

void generateNext(int *a, bool &isOk) {
	int i = MAX-1;
	while(i >= 0 && a[i] == 9) {
		a[i] = 0; i--;
	}
	if(i >= 0) {
		a[i] = 9;
	} else isOk = true;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		int a[MAX] = {0};
		a[MAX-1] = 9;
		bool isOk = false;
		while(!isOk) {
			if(valueOf(a) % n == 0) {
				cout << valueOf(a) << endl;
				break;
			}
			generateNext(a, isOk);
		}
	} 
}
