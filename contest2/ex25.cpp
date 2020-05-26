#include <bits/stdc++.h>
using namespace std;

void Try(int i, int n, int s, int sum, bool &can, int *a, int *result) {
	int j = (i == 0)?0:result[i-1]+1;
	for(j; j < n; j++) {
		result[i] = j;
		if((s+a[j])*2 == sum)
			can = true;
		else if(sum > 2*(s+a[j]))Try(i+1, n, s+a[j], sum, can, a, result);
		if(can)
			break;
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n, sum = 0; cin >> n;
		int *a = new int[n];
		int *result = new int[n];
		bool can = false;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if(sum%2==0)Try(0, n, 0, sum, can, a, result);
		if(can)
			cout << "YES\n";
		else cout << "NO\n";
	}
}
