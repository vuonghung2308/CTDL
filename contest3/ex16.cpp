#include <iostream>
using namespace std;

string greedy(int s, int d) {
	if(s > d*9 || s < 1) return "-1";
	string res(d, '0');
	int sum = 1, x = 9, i = d-1;
	while(i >= 0) {
		while(sum + x <= s && i >= 0) {
			sum = sum + x;
			res[i--] += x;
		}
		x--;
	}
	res[0]++;
	return res;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int s, d; cin >> s >> d;
		cout << greedy(s, d) << endl;
	}
}
