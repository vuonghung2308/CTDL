#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node *left;
	node *right;
	node(int V)
	{
		val=V;
		left=right=NULL;
	}
};
node *insert(node* root,int val)
{
	if(root==NULL)
	{
		return new node(val);
	}
	if(val < root->val) root->left = insert(root->left, val);
	else root->right = insert(root->right,val);
	return root;
}
void NodeLeaf(node* root)
{
	if(root==NULL) return;
	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->val<<" ";
		return;
	}
	if(root->left) NodeLeaf(root->left);
	if(root->right) NodeLeaf(root->right);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		node *root=NULL;
		int n; cin>>n;
		while(n--)
		{
			int x; cin>>x;
			root=insert(root,x);
		}
		NodeLeaf(root);
		cout<<endl;
	}
	return 0;
}
			
