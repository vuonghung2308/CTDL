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
	if((*root) != NULL && (*root)->data == u) {
		if(x == 'L')
			(*root)->left = new node(v);
		else (*root)->right = new node(v);
	} else {
		if((*root)->right != NULL) 
			addNode(u, v, x, &(*root)->right);
		if((*root)->left != NULL) addNode(u, v, x, &(*root)->left);
	}
}

void levelOrder(node *root) {
	stack<node*> s1, s2;
	if(root) s1.push(root);
	while(!s1.empty() || !s2.empty()) {
		while(!s1.empty()) {
			node *tmp = s1.top(); s1.pop();
			cout << tmp->data << ' ';
			if(tmp->right)
				s2.push(tmp->right);
			if(tmp->left)
				s2.push(tmp->left);
		}
		
		while(!s2.empty()) {
			node *tmp = s2.top(); s2.pop();
			cout << tmp->data << ' ';
			if(tmp->left)
				s1.push(tmp->left);
			if(tmp->right)
				s1.push(tmp->right);
		}
	}
	cout << endl;
}

int main() {
	int t; cin >> t;
	for(int z = 0; z < t; z++) {
		int n, u, v; char x;
		cin >> n >> u >> v >> x;
		node *root = new node(u);
		addNode(u, v, x, &root);
		for(int i = 1; i < n; i++) {
			cin >> u >> v >> x;
			addNode(u, v, x, &root);
		}
		levelOrder(root);
		delete root;
	}
}
