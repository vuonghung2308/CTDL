#include <iostream>
using namespace std;

bool binarysearch(int a[], int l, int r, int x) {
	if(r >= l) {	
		int mid = (l+r)/2;
		if(a[mid] == x)
			return true;
		if(a[mid] < x)
			return binarysearch(a, mid+1, r, x);
		return binarysearch(a, l, mid-1, x);
	}
	return false;
}

int count(int t[], int s[], int k) {
	int c = 0;
	for(int i = 0; i < k; i++)
		if(binarysearch(s, 0, k-1, t[i]))
			c++;
	return k - c;
} 

bool generateNext(int a[], int k, int n) {
	int i = k-1;
	while(a[i] == n+i+1-k)
		i--;
	int t = (i >= 0)?a[i]:0;
	if(i >= 0) {
		for(int j = i; j < k; j++)
			a[j] = ++t;
		return false;
	} else return true;
}


int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		int a[k], t[k];
		for(int j = 0; j < k; j++) {
			cin >> a[j];
			t[j] = a[j];
		}
		if(generateNext(a, k, n) == false)
			cout << count(t, a, k) << endl;
		else cout << k << endl;
	}
}
