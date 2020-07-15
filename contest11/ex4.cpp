#include <bits/stdc++.h>
using namespace std;

struct node {
	int key;
	node *left, *right;
	node(int x) {
		this->key = x;
		left = right = NULL;
	}
};

void insert(node **root, int x) {
	if(*root == NULL) {
		(*root) = new node(x);
	} else {
		if(x < (*root)->key)
			insert(&(*root)->left, x);
		else insert(&(*root)->right, x);
	}
}

void postorder(node *root) {
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->key << ' ';
}


int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		node *root = NULL;
		for(int i = 0; i < n; i++) {
			int t; cin >> t;
			insert(&root, t);
		}
		postorder(root);
		cout << endl;
	}
}
