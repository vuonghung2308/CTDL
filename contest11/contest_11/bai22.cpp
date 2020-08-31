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
int NodeTrungGian(node* root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL)) return 0;
	return 1 + NodeTrungGian(root->left) + NodeTrungGian(root->right);
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
		cout<<NodeTrungGian(root)<<endl;
	}
	return 0;
}
			
