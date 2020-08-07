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

bool check(node *root1, node *root2) {
	if((root1 && !root2) || (!root1 && root2))
		return false;
	if(!root1 && !root2)
		return true;
	if(root1->data == root2->data) {
		if(root1->left && root2->left)
			if(!check(root1->left, root2->left))
				return false;
		if(root1->right && root2->right)
			if(!check(root1->right, root2->right))
				return false;
		return true;
	} else return false;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x< t; x++) {
		int n, m; cin >> n;
		point points1[n] = {};
		node *root1 = NULL, *root2 = NULL;
		for(int i = 0; i < n; i++) {
			cin >> points1[i].u >> points1[i].v 
				>> points1[i].x;
		}
		cin >> m;
		point points2[m] ={};
		for(int i = 0; i < m; i++) {
			cin >> points2[i].u >> points2[i].v 
				>> points2[i].x;
		}
		addNode(n, points1, &root1);
		addNode(m, points2, &root2);
		cout << check(root1, root2) << "\n";
	}
}
