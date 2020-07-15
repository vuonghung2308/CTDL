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

int find(int *a, int n, int x) {
	for(int i = 0; i < n; i++)
		if(x == a[i])
			return i;
	return -1;
}

void postorder(node *root) {
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->key << ' ';
}

void addNode(int n, int *pre, int *ino, node **root) {
	(*root) = new node(pre[0]);
	if(n > 1) {
		int i = find(ino, n, pre[0]);
		addNode(i, pre+1, ino, &(*root)->left);
		if(i != n-1) addNode(n-1-i, pre+i+1, ino+i+1, &(*root)->right);
	}	
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int n; cin >> n;
		int ino[n], pre[n];
		node *root = NULL;
		for(int i = 0; i < n; i++)
			cin >> ino[i];
		for(int i = 0; i < n; i++)
			cin >> pre[i];
		addNode(n, pre, ino, &root);
		postorder(root);
		cout << endl;
	}
}
