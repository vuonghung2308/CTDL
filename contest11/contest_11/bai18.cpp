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

void preorder(node* root)
{
	if(root!=NULL)
	{
		cout<<root->val<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void solve()
{
	int n;
	cin>>n;
	int a[n+5];
	node *root=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		root=insert(root,a[i]);
	}
	preorder(root);
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
			
