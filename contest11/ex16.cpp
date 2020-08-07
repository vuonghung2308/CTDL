#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
	node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};


void addNode(int u, int v, char x, node **root) {
	if((*root) && (*root)->data == u) {
		if(x == 'L')
			(*root)->left = new node(v);
		else (*root)->right = new node(v);
	} else if(root) {
		if((*root)->left) addNode(u, v, x, &(*root)->left);
		if((*root)->right) addNode(u, v, x, &(*root)->right);
	}
}

bool isLeaf(node *root) {
	if(!root)
		return false;
	if(!root->left && !root->right)
		return true;
	return false;
}

int sumMax(node *root,int &m) {
	if(!root)
		return 0;
	if(isLeaf(root))
		return root->data;
	int ri = sumMax(root->right, m);
	int le = sumMax(root->left, m);
	if(root->left && root->right) {
		m = max(m, ri+le+root->data);
		return max(ri, le) + root->data;
	}
	if(!root->left)
		return ri + root->data;
	return le + root->data;
}

int main() {
	int t; cin >> t;
	for(int z = 0; z< t; z++) {
		int n; cin >> n;
		node *root = NULL;
		int u, v; char x;
		cin >> u >> v >> x;
		root = new node(u);
		addNode(u, v, x, &root);
		for(int i = 1; i < n; i++)  {
			cin >> u >> v >> x;
			addNode(u, v, x, &root);
		}
		int m = INT_MIN;
		sumMax(root, m);
		cout << m << "\n";
	}
}

