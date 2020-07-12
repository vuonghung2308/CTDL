#include <iostream>
using namespace std;

void show(int *a, int n) {
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void sort(int *a, int n) {
	for(int i = 0; i < n; i++) {
		int j = i;
		while(j > 0 && a[j] < a[j-1]) {
			swap(a[j], a[j-1]);
			j = j - 1;
		}
		cout << "Buoc " << i << ": ";
		show(a, i+1);
	}
}

int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, n);
}
