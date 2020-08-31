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
node* ConstructTree(int n)
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
void SpiralOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*> s1;
    stack<node*> s2;
    s1.push(root);
    while(!s1.empty()||!s2.empty())
    {
        while(!s1.empty())
        {
            node* temp=s1.top();
            s1.pop();
            cout<<temp->value<<" ";
            if(temp->right)
            {
                s2.push(temp->right);
            }
            if(temp->left)
            {
                s2.push(temp->left);
            }
        }
        while(!s2.empty())
        {
            node* temp=s2.top();
            s2.pop();
            cout<<temp->value<<" ";
            if(temp->left)
            {
                s1.push(temp->left);
            }
            if(temp->right)
            {
                s1.push(temp->right);
            }
        }
    }
}
void solve()
{
	int n; cin>>n;
	node *root=ConstructTree(n);
	SpiralOrder(root);
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
