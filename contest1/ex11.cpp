#include <iostream>
#include <string>
using namespace std;

string graytobinary(string gray) {
	string binary = ""; 
    binary += gray[0]; 
    for (int i = 1; i < gray.length(); i++) { 
        if (gray[i] == '0') 
            binary += binary[i - 1]; 
        else
            binary += (binary[i - 1] == '0') ? '1' : '0'; 
    } 
    return binary; 
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s; cin >> s;
		cout << graytobinary(s) << endl;
	}
}
