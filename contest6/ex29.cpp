#include <iostream>
using namespace std;

void show(int *a, int n) {
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void sort(int *a, int n) {
	for(int i = 0; i < n-1; i++) {
		bool swapped = false;
		for(int j = 0; j < n-i-1; j++) {
			if(a[j] > a[j+1]) {
				swap(a[j], a[j+1]);
				swapped = true;
			}
		}
		if(!swapped)
			break;
		cout << "Buoc " << i+1 << ": ";
		show(a, n);
	}
}

int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, n);
}
