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
	stack<node*> S;
	queue<node*> Q;
	Q.push(root);
	S.push(root);
	while(!Q.empty()) {
		node *tmp = Q.front(); Q.pop();
		if(tmp->right) {
			Q.push(tmp->right);
			S.push(tmp->right);
		}
		if(tmp->left) {
			Q.push(tmp->left);
			S.push(tmp->left);
		}
	}
	while(!S.empty()) {
		cout << S.top()->data << ' ';
		S.pop();
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

