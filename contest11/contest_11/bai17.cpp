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
/*node* ConstructTree(int n)
{
	node *root=NULL;
	queue<node *> q;
	for(;n>0;n--)
	{
		int a,b;
		char c;
		cin>>a>>b>>c;
		if(!root)
		{
			root=new node(a);
			q.push(root);
		}
		node *t=q.front(); q.pop();
		if(c=='L')
		{
			t->left=new node(b);
			q.push(t->left);
		}
		else 
		if(c=='R')
		{
			t->right=new node(b);
			q.push(t->right);
		}
		n--;
		if(!n) break;
		cin>>a>>b>>c;
		if(c=='R')
		{
			t->right=new node(b);
			q.push(t->right);
		}
		else
		if(c=='L')
		{
			t->left=new node(b);
			q.push(t->left);
		}
	}
	return root;
}*/
node *ConstructTree(int n)
{
	map<int,node *> m;
	node *root=NULL;
	while(n--)
	{
		int a,b;
		char c;
		cin>>a>>b>>c;
		node *cha;
		if(m.find(a)==m.end())
		{
			cha=new node(a);
			m[a]=cha;
			if(root==NULL)
			root=cha;
		}
		else cha=m[a];
		node *con=new node(b);
		if(c=='L')
		cha->left=con;
		else if(c=='R')
		cha->right=con;
		m[b]=con;
	}
	return root;
}
void inorder(node *root,vector<int> &in)
{
	if(!root)
	return;
	inorder(root->left,in);
	in.push_back(root->value);
	inorder(root->right,in);
}
void bst(node *root,vector<int> &in,int &id)
{
	if(!root) return;
	bst(root->left,in,id);
	root->value=in[id++];
	bst(root->right,in,id);
}
node *BinaryTreeToBST(node *root)
{
	vector<int> in;
	inorder(root,in);
	sort(in.begin(),in.end());
	int id=0;
	bst(root,in,id);
	return root;
}
void InOrder(node *root)
{
	if(root==NULL) return;
	InOrder(root->left);
	cout<<root->value<<" ";
	InOrder(root->right);
}
void solve()
{
	int n,m; cin>>n;
	node *root=ConstructTree(n);
	node *bst=BinaryTreeToBST(root);
	InOrder(bst);
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
