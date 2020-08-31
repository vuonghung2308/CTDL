#include<bits/stdc++.h>
using namespace std;
struct node{
	int value;
	node *left,*right;
	node(int x)
	{
		value=x;
		left=NULL;
		right=NULL;
	}
};
node *Tree(int inorder[],int levelorder[],int st,int en,int n)
{
	if(n<=0)
	return NULL;
	node *root=new node(levelorder[0]);
	int id=-1;
	for(int i=st;i<=en;i++)
	{
		if(levelorder[0]==inorder[i])
		{
			id=i;
			break;
		}
	}
	unordered_set<int> s;
	for(int i=st;i<id;i++)
	s.insert(inorder[i]);
	int left[s.size()];
	int right[en-st-s.size()];
	int l=0,r=0;
	for(int i=1;i<n;i++)
	{
		if(s.find(levelorder[i]) != s.end())
		left[l++]=levelorder[i];
		else right[r++]=levelorder[i];
	}
	root->left=Tree(inorder,left,st,id-1,id-st);
	root->right=Tree(inorder,right,id+1,en,en-id);
	return root;
}
void postorder(node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->value<<" ";
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int inorder[n+5],levelorder[n+5];
		for(int i=0;i<n;i++)
		   cin>>inorder[i];
		for(int i=0;i<n;i++)
		   cin>>levelorder[i];
		node *root=Tree(inorder,levelorder,0,n-1,n);
		postorder(root);
		cout<<endl;
	}
	return 0;
}
