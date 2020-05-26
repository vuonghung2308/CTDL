#include <iostream>
using namespace std;

void Try(int i, int n, int k, int pre, int sum, int s, int &num) {
	for(int j = pre+1; j <= n; j++) {
		if(j+sum+n*(k-i-1) >= s) {
			if(i == k-1) {
				if(sum+j == s) num++;
			} else if(sum+j < s) Try(i+1, n, k, j, sum+j, s, num);
		}
	}
}

int main() {
	int n = 1, k = 1, s= 1;
	while(true) {
		cin >> n >> k >> s;
		if(n == 0 && k == 0 && s == 0)
			break;
		int num = 0;
		Try(0, n, k, 0, 0, s, num);
		cout << num << endl;
	};
}
