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

struct point{
	int u;
	int v;
	char x;
};

void addNode(int n, point *points, node **root) {
	map<int, node*> m;
	for(int i = 0; i < n; i++) {
		if(m.find(points[i].u) == m.end()) {
			(*root) = new node(points[i].u);
			if(points[i].x == 'L') {
				(*root)->left = new node(points[i].v);
				m[points[i].v] = (*root)->left;
			}
			else {
				(*root)->right = new node(points[i].v);
				m[points[i].v] = (*root)->right;
			}
			m[points[i].u] = (*root);
		} else {
			if(points[i].x == 'L'){
				m[points[i].u]->left = new node(points[i].v);
				m[points[i].v] = m[points[i].u]->left;
			} else {
				m[points[i].u]->right = new node(points[i].v);
				m[points[i].v] = m[points[i].u]->right;
			}
		}
	}
}

bool isLeaf(node *root) {
	if(!root)
		return false;
	if(!root->left && !root->right)
		return true;
	return false;
}

bool check(node *root) {
	if(!root || isLeaf(root))
		return true;
	if(check(root->left) && check(root->right)) {
		int sumLeft = 0, sumRight = 0;
		if(isLeaf(root->left))
			sumLeft = root->left->data;
		else sumLeft = 2 * (root->left->data);
		
		if(isLeaf(root->right))
			sumRight = root->right->data;
		else sumRight = 2 * (root->right->data);
		
		return (root->data == sumLeft + sumRight);
	}
	return false;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x< t; x++) {
		int n; cin >> n;
		point points[n] = {};
		node *root = NULL;
		for(int i = 0; i < n; i++) {
			cin >> points[i].u >> points[i].v 
				>> points[i].x;
		}
		addNode(n, points, &root);
		cout << check(root) << endl;
	}
}
