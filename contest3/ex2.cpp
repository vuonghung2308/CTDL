#include <iostream>
using namespace std;

int sum(string a, string b) {
	int x = 0, y = 0;
	for(int i = 0; i < a.size(); i++) 
		x = x * 10 + a[i] - '0';
	for(int i = 0; i < b.size(); i++)
		y = y * 10 + b[i] - '0';
	return x + y;
}

int greedy_min(string a, string b) {
	for(int i = 0; i < a.size(); i++)
		if(a[i] == '6') a[i] = '5';
	for(int i = 0; i < b.size(); i++)
		if(b[i] == '6') b[i] = '5';
	return sum(a, b);
}

int greedy_max(string a, string b) {
	for(int i = 0; i < a.size(); i++)
		if(a[i] == '5') a[i] = '6';
	for(int i = 0; i < b.size(); i++)
		if(b[i] == '5') b[i] = '6';
	return sum(a, b);
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << greedy_min(a, b) << ' ' << greedy_max(a, b);
}
