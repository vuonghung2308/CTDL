#include <iostream>
using namespace std;

struct Stack{
	int top;
	int a[200];
};

int main() {
	string key;
	Stack s;
	s.top = -1;
	while(true) {
		cin >> key;
		if(key == "push") {
			int value; cin >> value;
			s.top = s.top + 1;
			s.a[s.top] = value;
		} else if(key == "pop") {
			if(s.top != -1)
				s.top = s.top-1;
			if(s.top == -1)  {
				cout << "empty\n";
				break;
			}
		} else {
			if(s.top == -1){
				cout << "empty\n";
				break;
			} else {
				for(int i = 0; i <= s.top; i++)
					cout << s.a[i] << ' ';
				cout << endl;
			}
		}
	}
}
