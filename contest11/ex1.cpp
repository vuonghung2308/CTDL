//pc2 co dau cach con web thi khong

#include <bits/stdc++.h>
using namespace std;

struct node{
	char key;
	node *left;
	node *right;
	node(char x) {
		this->key = x;
		left = right = NULL;
	}
};

void inorder(node *root) {
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->key;
	inorder(root->right);
}

bool isOperator(char c) {
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
	   return true;
	return false;
}

void tree(string s) {
	stack<node *> stack;
	int len = s.length();
	for(int i = 0; i < len; i++) {
		if(isOperator(s[i]) ) {
			node *h = new node(s[i]);
			node *r = stack.top(); stack.pop();
			node *l = stack.top(); stack.pop();
			h->left = l;
			h->right = r;
			stack.push(h);
		} else {
			stack.push(new node(s[i]));
		}
	}
	inorder(stack.top());
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s ="";
		while(s == "")
			cin >> s;
		tree(s); cout << endl;
	}
}
