#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	string data;
	node *left,*right;
};
node* newNode(string s)
{
	node *tmp=new node;
	tmp->left=tmp->right=NULL;
	tmp->data=s;
	return tmp;
}
bool isOperator(string s)
{
	if(s=="+" || s=="-" || s=="*" || s=="/" || s=="^")
	   return true;
	return false;
}
ll tinh(node* root)
{
	if(!root)
	return 0;
	if(!root->left && !root->right)
	return stoi(root->data);
	ll l=tinh(root->left);
	ll r=tinh(root->right);
	if(root->data=="+")
	   return l+r;
	if(root->data=="-")
	return l-r;
	if(root->data=="*")
	return l*r;
	if(root->data=="/")
	return l/r;
}
void solve()
{
	int n;
	cin>>n;
	string s[n+5];
	for(int i=0;i<n;i++)
	   cin>>s[i];
	queue<node *> q;
	int cnt=0;
	node *root=newNode(s[cnt++]);
	q.push(root);
	while(!q.empty())
	{
		node *tmp=q.front(); q.pop();
		if(isOperator(tmp->data))
		{
			node *left=newNode(s[cnt++]);
			node *right=newNode(s[cnt++]);
			tmp->left=left;
			tmp->right=right;
			q.push(left);
			q.push(right);
		}
	}
	cout<<tinh(root)<<endl;
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
