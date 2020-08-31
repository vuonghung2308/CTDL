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
/*node *ConstructTree(int n)
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
}*/
void insert(node *root, int cha, int con, char c)
{
    if(cha==root->value)
    {
        if(c=='L')
        {
            root->left=new node(con);
            return;
        }
        if(c=='R')
        {
            root->right=new node(con);
            return;
        }
    }
    else if(root->left==NULL && root->right==NULL)
    {
        return;
    }
    else
    {
        if(root->left)
        {
            insert(root->left, cha, con, c);
        }
        if(root->right)
        {
            insert(root->right,cha,con, c);
        }
    }
}
int maxUtil(node *root,int &ans)
{
	if(root==NULL) 
	return 0;
	if(root->left==NULL && root->right==NULL) 
	return root->value;
	int left=maxUtil(root->left,ans);
	int right=maxUtil(root->right,ans);
	if(root->left && root->right)
	{
		ans=max(ans,left+right+root->value);
		return (max(left,right)+root->value);
	}
	if(root->left==NULL) 
	return right+root->value;
    return left+root->value;
}
void solve()
{
	int n; cin>>n;
	node *root=NULL;
	int a,b;
	char c;
	cin>>a>>b>>c;
	root=new node(a);
	insert(root,a,b,c);
	for(int i=1;i<n;i++)
	{
		cin>>a>>b>>c;
		insert(root,a,b,c);
	}
	int ans=INT_MIN;
	maxUtil(root,ans);
	cout<<ans<<endl;
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
