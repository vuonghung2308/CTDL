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
int depth(node* root)
{
	if(root==NULL)
	return 0;
	else
	{
		int l=depth(root->left);
		int r=depth(root->right);
		return max(l,r)+1;
	}
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
		cout<<depth(root)-1<<endl;
	}
	return 0;
}
			
