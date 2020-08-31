#include<bits/stdc++.h>
using namespace std;
struct node{
	int value;
	node *left,*right;
	node(int x){
		value=x;
		left=right=NULL;
	}
};
node *BalancedBST(int a[],int st,int en)
{
	if(st>en) return NULL;
	int m=(st+en)/2;
	node *root=new node(a[m]);
	root->left=BalancedBST(a,st,m-1);
	root->right=BalancedBST(a,m+1,en);
	return root;
}
void preorder(node *root)
{
	if(root)
	{
		cout<<root->value<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void solve()
{
	int n; cin>>n;
	int a[n+5];
	for(int i=0;i<n;i++)
	   cin>>a[i];
	sort(a,a+n);
	node *root=BalancedBST(a,0,n-1);
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
