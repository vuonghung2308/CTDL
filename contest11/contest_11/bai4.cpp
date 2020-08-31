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
void postorder(node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->val<<" ";
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
		postorder(root);
		cout<<endl;
	}
	return 0;
}
			
