#include <iostream>
using namespace std;

bool check(char *res) {
	int x = res[0] - '0';
	for(int i = 1; i <= 4; i++) {
		switch(res[i*2-1]) {
			case '+': {
				x += (res[i*2] -'0');
				break;
			}
			case '-': {
				x -= (res[i*2] -'0');
				break;
			}
			case '*': {
				x *= (res[i*2] -'0');
				break;
			}
		}
	}
	return x == 23;
}

void Try(int i, char *a, char *sign, char *res, bool *visited, bool &has) {
	if(i%2==0) {
		for(int j = 0; j < 5; j++) {
			if(visited[j] == false) {
				visited[j] = true;
				res[i] = a[j];
				if(i == 8) {
					if(check(res)) has = true;
				}
				else if(i < 8) Try(i+1, a, sign, res, visited, has);
				visited[j] = false;
			}
			if(has) break;
		}
		
	} else {
		for(int j = 0; j < 3; j++) {
			if(has) break;
			res[i] = sign[j];
			Try(i+1, a, sign, res, visited, has);
		}
		
	}
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		char a[5], sign[] = {'+', '-', '*'};
		bool has = false, visited[5] = {false};
		cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
		char res[9] = {""};
		Try(0, a, sign, res, visited, has);
		if(has) cout << "YES\n";
		else cout << "NO\n";
	}
}
